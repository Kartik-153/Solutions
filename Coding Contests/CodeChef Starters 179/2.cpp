#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        int *x = (int *)malloc(n * sizeof(int)), *y = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &y[i]);
        long long s = 0;
        int mO = 1000000000;
        for (int i = 0; i < n; i++) {
            int a = x[i] - 1, b = y[i] - 1, d = (b - a + 9) % 9;
            int l = (d == 0) ? 0 : (d <= 9 - d ? d : 9 - d);
            s += l;
            int alt = (d == 0) ? 9 : (d <= 9 - d ? 9 - d : d);
            int odd = alt - l;
            if (odd < mO)
                mO = odd;
        }
        long long r = k - s;
        if (k < s) {
            printf("NO\n");
            free(x);
            free(y);
            continue;
        }
        if (r % 2 == 0 || r >= mO)
            printf("YES\n");
        else
            printf("NO\n");
        free(x);
        free(y);
    }
    return 0;
}