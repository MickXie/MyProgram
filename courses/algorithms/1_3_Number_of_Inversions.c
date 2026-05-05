#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long merge_count(int *a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc((n1 + 1) * sizeof(int));
    int *R = (int *)malloc((n2 + 1) * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    long long count = 0;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i++];
        } else {
            /* R[j] < L[i], so R[j] forms an inversion with all remaining L[i..n1-1] */
            count += (n1 - i);
            a[k] = R[j++];
        }
    }

    free(L);
    free(R);
    return count;
}

long long merge_sort(int *a, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long count = 0;
    count += merge_sort(a, left, mid);
    count += merge_sort(a, mid + 1, right);
    count += merge_count(a, left, mid, right);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%lld\n", merge_sort(a, 0, n - 1));

    free(a);
    return 0;
}
