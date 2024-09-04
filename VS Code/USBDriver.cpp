#-- - T2 - COPYRIGHT - NOTE - BEGIN -- -
#T2 SDE : package /*/linux/xserve-frontpanel.patch                                      \
 # Copyright (C) 2024 The T2 SDE Project                                                \
 #                                                                                      \
 # This Copyright note is generated by scripts/Create-CopyPatch,                        \
 # more information can be found in the files COPYING and README.                       \
 #                                                                                      \
 # This patch file is dual-licensed. It is available under the license the              \
 # patched project is licensed under, as long as it is an OpenSource license            \
 # as defined at http://www.opensource.org/ (e.g. BSD, X11) or under the terms          \
 # of the GNU General Public License version 2 as used by the T2 SDE.                   \
 # --- T2-COPYRIGHT-NOTE-END ---                                                        \
                                                                                        \
 This adds a new driver to monitor the cpu load and control the Apple                   \
 Xserve Intel Xeon server front-panel LEDs.                                             \
                                                                                        \
 Signed-off-by: RenÃ© Rebe <rene@exactcode.com>                                       \
                                                                                        \
 --- linux-6.9/drivers/usb/misc/Kconfig.vanilla	2024-07-22 19:25:05.350678337 +0200     \
 +++ linux-6.9/drivers/usb/misc/Kconfig	2024-07-22 19:25:23.560676582 +0200             \
 @@ -331,3 +331,10 @@                                                                   \
       this config will enable the driver and it will automatically                     \
       match the state of the USB subsystem. If this driver is a                        \
       module it will be called onboard_usb_dev.                                        \
 +                                                                                      \
 +config USB_XSERVE_FRONTPANEL                                                          \
 +	tristate "Apple Xserve frontpanel support"                                           \
 +	depends on X86                                                                       \
 +	help                                                                                 \
 +	  Say Y here if you want to control the frontpanel of Apple Xserve                   \
 +	  servers over USB.                                                                  \
 --- linux-6.8/drivers/usb/misc/Makefile.vanilla	2024-05-09 18:36:44.386205674 +0200    \
 +++ linux-6.8/drivers/usb/misc/Makefile	2024-05-09 18:37:25.977208996 +0200            \
 @@ -29,6 +29,7 @@                                                                      \
  obj-$(CONFIG_USB_HSIC_USB3503)		+= usb3503.o                                          \
  obj-$(CONFIG_USB_HSIC_USB4604)		+= usb4604.o                                          \
  obj-$(CONFIG_USB_CHAOSKEY)		+= chaoskey.o                                             \
 +obj-$(CONFIG_USB_XSERVE_FRONTPANEL)	+= xserve-frontpanel.o                            \
                                                                                        \
  obj-$(CONFIG_USB_SISUSBVGA)		+= sisusbvga/                                            \
  obj-$(CONFIG_USB_LINK_LAYER_TEST)	+= lvstest.o                                        \
 --- /dev/null	2024-04-27 11:06:15.379862889 +0200                                      \
 +++ linux-6.8/drivers/usb/misc/xserve-frontpanel.c	2024-05-12 18:31:15.538230373 +0200 \
 @@ -0,0 +1,400 @@                                                                      \
 +// SPDX-License-Identifier: GPL-2.0                                                   \
 +/*                                                                                    \
 + * Apple Xserve USB front-panel driver.                                               \
 + * Copyright (C) 2024 RenÃ© Rebe <rene@exactcode.com>                               \
 + *                                                                                    \
 + * based on RackMac vu-meter driver                                                   \
 + * (c) Copyright 2006 Benjamin Herrenschmidt, IBM Corp.                               \
 + *                    <benh@kernel.crashing.org>                                      \
 + *                                                                                    \
 + * based on USB Skeleton driver - 2.2                                                 \
 + * Copyright (C) 2001-2004 Greg Kroah-Hartman (greg@kroah.com)                        \
 + *                                                                                    \
 + */
+
    + // #define DEBUG
    +
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kref.h>
#include <linux/uaccess.h>
#include <linux/usb.h>
#include <linux/mutex.h>
#include <linux/cpufreq.h>

#define PANEL_VENDOR 0x5ac
#define PANEL_PRODUCT 0x8261
#define PANEL_CONFIG 0
#define PANEL_DATA_SIZE 32

/* CPU meter sampling rate in ms */
#define CPU_SAMPLING_RATE 250

    /* table of devices that work with this driver */
    static const struct usb_device_id frontpanel_table[] = {
    {USB_DEVICE(PANEL_VENDOR, PANEL_PRODUCT)},
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, frontpanel_table);

/*
+ * MAX_TRANSFER is chosen so that the VM is not stressed by
+ * allocations > PAGE_SIZE and the number of packets in a page
+ * is an integer 512 is the largest possible packet on EHCI
+ */
#define WRITES_IN_FLIGHT 8
/* arbitrarily chosen */

struct rackmeter_cpu
{
    u64 prev_wall;
    u64 prev_idle;
};

/* Structure to hold all of our device specific stuff */
struct usb_frontpanel
{
    struct usb_device *udev;         /* the usb device for this device */
    struct usb_interface *interface; /* the interface for this device */
    struct semaphore limit_sem;      /* limiting the number of writes in progress */
    struct usb_anchor submitted;     /* in case we need to retract our submissions */
    int errors;                      /* the last request tanked */
    spinlock_t err_lock;             /* lock for errors */
    struct kref kref;
    struct mutex io_mutex;      /* synchronize I/O with disconnect */
    __u8 bulk_out_endpointAddr; /* the address of the bulk out endpoint */
    unsigned long disconnected : 1;

    struct delayed_work sniffer;

    __u8 buffer[PANEL_DATA_SIZE];
    struct rackmeter_cpu cpu[16];
};
#define to_fp_dev(d) container_of(d, struct usb_frontpanel, kref)

static void frontpanel_draw_down(struct usb_frontpanel *dev);

static void frontpanel_delete(struct kref *kref)
{
    struct usb_frontpanel *dev = to_fp_dev(kref);

    usb_put_intf(dev->interface);
    usb_put_dev(dev->udev);
    kfree(dev);
}

static void frontpanel_write_bulk_callback(struct urb *urb)
{
    struct usb_frontpanel *dev;
    unsigned long flags;

    dev = urb->context;

    /* sync/async unlink faults aren't errors */
    if (urb->status)
    {
        if (!(urb->status == -ENOENT ||
              urb->status == -ECONNRESET ||
              urb->status == -ESHUTDOWN))
            dev_err(&dev->interface->dev,
                    "%s - nonzero write bulk status received: %d\n",
                    __func__, urb->status);

        spin_lock_irqsave(&dev->err_lock, flags);
        dev->errors = urb->status;
        spin_unlock_irqrestore(&dev->err_lock, flags);
    }

    /* free up our allocated buffer */
    usb_free_coherent(urb->dev, urb->transfer_buffer_length,
                      urb->transfer_buffer, urb->transfer_dma);
    up(&dev->limit_sem);
}

static ssize_t frontpanel_write(struct usb_frontpanel *dev, const char *buffer, size_t count)
{
    int retval = 0;
    struct urb *urb = NULL;
    char *buf = NULL;
    size_t writesize = min_t(size_t, count, PANEL_DATA_SIZE);

    /*
     * limit the number of URBs in flight to stop a user from using up all
     * RAM
     */
    if (down_trylock(&dev->limit_sem))
    {
        retval = -EAGAIN;
        goto exit;
    }

    spin_lock_irq(&dev->err_lock);
    retval = dev->errors;
    if (retval < 0)
    {
        /* any error is reported once */
        dev->errors = 0;
        /* to preserve notifications about reset */
        retval = (retval == -EPIPE) ? retval : -EIO;
    }
    spin_unlock_irq(&dev->err_lock);
    if (retval < 0)
        goto error;

    /* create a urb, and a buffer for it, and copy the data to the urb */
    urb = usb_alloc_urb(0, GFP_KERNEL);
    if (!urb)
    {
        retval = -ENOMEM;
        goto error;
    }

    buf = usb_alloc_coherent(dev->udev, writesize, GFP_KERNEL,
                             &urb->transfer_dma);
    if (!buf)
    {
        retval = -ENOMEM;
        goto error;
    }

    memcpy(buf, buffer, writesize);

    /* this lock makes sure we don't submit URBs to gone devices */
    mutex_lock(&dev->io_mutex);
    if (dev->disconnected)
    { /* disconnect() was called */
        mutex_unlock(&dev->io_mutex);
        retval = -ENODEV;
        goto error;
    }

    /* initialize the urb properly */
    usb_fill_bulk_urb(urb, dev->udev,
                      usb_sndbulkpipe(dev->udev, dev->bulk_out_endpointAddr),
                      buf, writesize, frontpanel_write_bulk_callback, dev);
    urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
    usb_anchor_urb(urb, &dev->submitted);

    /* send the data out the bulk port */
    +retval = usb_submit_urb(urb, GFP_KERNEL);
    +mutex_unlock(&dev->io_mutex);
    +if (retval)
    {
        +dev_err(&dev->interface->dev,
                 +"%s - failed submitting write urb, error %d\n",
                 +__func__, retval);
        +goto error_unanchor;
        +
    }
    + +/*
   +	 * release our reference to this urb, the USB core will eventually free
   +	 * it entirely
   +	 */
      +usb_free_urb(urb);
    + +return writesize;
    + +error_unanchor : +usb_unanchor_urb(urb);
    +error : +if (urb)
    {
        +usb_free_coherent(dev->udev, writesize, buf, urb->transfer_dma);
        +usb_free_urb(urb);
        +
    }
    +up(&dev->limit_sem);
    + +exit : +return retval;
    +
}
+
    + static void rackmeter_do_timer(struct work_struct *work) +
{
    +struct usb_frontpanel *dev = container_of(work, struct usb_frontpanel, sniffer.work);
    + +unsigned int load, cpu, updated = 0;
    +u64 cpu_idle, cpu_wall;
    +s64 diff_idle, diff_wall;
    +ssize_t ret;
    + +for_each_online_cpu(cpu)
    {
        +struct rackmeter_cpu *rcpu;
        +if (cpu > 15) + continue;
        +rcpu = &dev->cpu[cpu];
        + +cpu_idle = get_cpu_idle_time(cpu, &cpu_wall, 0);
        +diff_idle = cpu_idle - rcpu->prev_idle;
        +diff_wall = cpu_wall - rcpu->prev_wall;
        +if (diff_idle > diff_wall) + diff_wall = diff_idle;
        + +/* We do a very dumb calculation to update the LEDs for now */
          +load = div64_u64(255 * (diff_wall - diff_idle), diff_wall);
        + +if (dev->buffer[cpu] != (__u8)load)
        {
            +dev->buffer[cpu] = (__u8)load;
            +updated = 1;
            +
        }
        + +rcpu->prev_idle = cpu_idle;
        +rcpu->prev_wall = cpu_wall;
        +
    }
    + +if (updated)
    {
        +ret = frontpanel_write(dev, dev->buffer, PANEL_DATA_SIZE);
        +if (ret <= 0) + dev_err(&dev->interface->dev, "write failed: %ld\n", ret);
        +
    }
    + +schedule_delayed_work_on(smp_processor_id(), &dev->sniffer, msecs_to_jiffies(CPU_SAMPLING_RATE));
    +
}
+
    + static void rackmeter_init_cpu_sniffer(struct usb_frontpanel *dev) +
{
    +unsigned int cpu;
    + +INIT_DELAYED_WORK(&dev->sniffer, rackmeter_do_timer);
    + +for_each_online_cpu(cpu)
    {
        +struct rackmeter_cpu *rcpu;
        +if (cpu > 15) + continue;
        +rcpu = &dev->cpu[cpu];
        + +rcpu->prev_wall = 0;
        +rcpu->prev_idle = 0;
        +
    }
    + +schedule_delayed_work_on(smp_processor_id(), &dev->sniffer, msecs_to_jiffies(CPU_SAMPLING_RATE));
    +
}
+
    +
    +static void rackmeter_stop_cpu_sniffer(struct usb_frontpanel *dev) +
{
    +cancel_delayed_work_sync(&dev->sniffer);
    +
}
+
    + static int frontpanel_probe(struct usb_interface *interface, +const struct usb_device_id *id) +
{
    +struct usb_frontpanel *dev;
    +struct usb_endpoint_descriptor *bulk_out;
    +int retval;
    + +/* allocate memory for our device state and initialize it */
      +dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    +if (!dev) + return -ENOMEM;
    + +kref_init(&dev->kref);
    +sema_init(&dev->limit_sem, WRITES_IN_FLIGHT);
    +mutex_init(&dev->io_mutex);
    +spin_lock_init(&dev->err_lock);
    +init_usb_anchor(&dev->submitted);
    + +dev->udev = usb_get_dev(interface_to_usbdev(interface));
    +dev->interface = usb_get_intf(interface);
    + +/* set up the endpoint information */
      +/* use only the first bulk-in and bulk-out endpoints */
      +retval = usb_find_common_endpoints(interface->cur_altsetting,
                                          +NULL, &bulk_out, NULL, NULL);
    +if (retval)
    {
        +dev_err(&interface->dev,
                 +"Could not find bulk-out endpoints\n");
        +goto error;
        +
    }
    + +dev->bulk_out_endpointAddr = bulk_out->bEndpointAddress;
    + +/* save our data pointer in this interface device */
      +usb_set_intfdata(interface, dev);
    + +rackmeter_init_cpu_sniffer(dev);
    + +return 0;
    + +error : +/* this frees allocated memory */
               +kref_put(&dev->kref, frontpanel_delete);
    + +return retval;
    +
}
+
    + static void frontpanel_disconnect(struct usb_interface *interface) +
{
    +struct usb_frontpanel *dev;
    +dev = usb_get_intfdata(interface);
    + +rackmeter_stop_cpu_sniffer(dev);
    + +/* prevent more I/O from starting */
      +mutex_lock(&dev->io_mutex);
    +dev->disconnected = 1;
    +mutex_unlock(&dev->io_mutex);
    + +usb_kill_anchored_urbs(&dev->submitted);
    + +/* decrement our usage count */
      +kref_put(&dev->kref, frontpanel_delete);
    +
}
+
    + static void frontpanel_draw_down(struct usb_frontpanel *dev) +
{
    +int time;
    + +time = usb_wait_anchor_empty_timeout(&dev->submitted, 1000);
    +if (!time) + usb_kill_anchored_urbs(&dev->submitted);
    +
}
+
    + static int frontpanel_suspend(struct usb_interface *intf, pm_message_t message) +
{
    +struct usb_frontpanel *dev = usb_get_intfdata(intf);
    + +if (!dev) + return 0;
    +frontpanel_draw_down(dev);
    +return 0;
    +
}
+
    + static int frontpanel_resume(struct usb_interface *intf) +
{
    +return 0;
    +
}
+
    + static int frontpanel_pre_reset(struct usb_interface *intf) +
{
    +struct usb_frontpanel *dev = usb_get_intfdata(intf);
    + +mutex_lock(&dev->io_mutex);
    +frontpanel_draw_down(dev);
    + +return 0;
    +
}
+
    + static int frontpanel_post_reset(struct usb_interface *intf) +
{
struct usb_frontpanel *dev = usb_get_intfdata(intf);
    /* we are sure no URBs are active - no locking needed */
    dev->errors = -EPIPE;
    +mutex_unlock(&dev->io_mutex);
    return 0;
    
}

     static struct usb_driver frontpanel_driver = {
    .name = "xserve-frontpanel",
    .probe = frontpanel_probe,
    .disconnect = frontpanel_disconnect,
    .suspend = frontpanel_suspend,
    .resume = frontpanel_resume,
    pre_reset = frontpanel_pre_reset,
    .post_reset = frontpanel_post_reset,
    .id_table = frontpanel_table,
    /*.supports_autosuspend = 1,*/
    };

     module_usb_driver(frontpanel_driver);

     MODULE_AUTHOR("RenÃ© Rebe");
 MODULE_DESCRIPTION("Apple Xserve USB front-panel driver");
 MODULE_LICENSE("GPL v2");
