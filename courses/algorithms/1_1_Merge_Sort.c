#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc((n1 + 1) * sizeof(int));
    int *R = (int *)malloc((n2 + 1) * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }

    free(L);
    free(R);
}

void merge_sort(int *a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
