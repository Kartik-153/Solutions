#include<stdio.h>
using namespace std;


int iteartive_Linear_search(int arr[], int key, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) 
            return 1;
    }
    return 0;
}

int recursive_linear_search(int arr[], int key, int n) {
    static int i = n;
    if(n < 0) {
        return 0;
    }
    if(arr[i] == key)
        return 1;
    i = n - 1;
    return recursive_linear_search(arr, key, i);
}

int recursive_binary_search(int arr[], int key, int n, int s, int end) {
    int mid = (s + end)/2;
    if(arr[mid] == key) {
        return 1;
    }
    if(arr[mid] > key) {
        recursive_binary_search(arr, key, n, s, mid);
    }
    if(arr[mid] < key) {
        recursive_binary_search(arr, key, n, mid, end);
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int n) {
    int i, j, id_min;
    for(i - 0; i < n - 1; i++) {
        id_min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[id_min]) {
                id_min = j;
            }
        }
        if(id_min != i)
        swap(&arr[id_min], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int array[], int n) {
  for (int step = 0; step < n - 1; ++step) {
    for (int i = 0; i < n - step - 1; ++i) {
        if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    mergeSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}

// difference between stable sorting 
// what is sorting in linear time