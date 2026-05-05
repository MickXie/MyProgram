#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long cross_max(int *a, int left, int mid, int right) {
    long long left_sum = LLONG_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += a[i];
        if (sum > left_sum) left_sum = sum;
    }

    long long right_sum = LLONG_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += a[i];
        if (sum > right_sum) right_sum = sum;
    }

    return left_sum + right_sum;
}

long long divide_and_conquer(int *a, int left, int right) {
    if (left == right) return a[left];

    int mid = (left + right) / 2;
    long long left_max  = divide_and_conquer(a, left, mid);
    long long right_max = divide_and_conquer(a, mid + 1, right);
    long long cross     = cross_max(a, left, mid, right);

    return max(max(left_max, right_max), cross);
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%lld\n", divide_and_conquer(a, 0, n - 1));

    free(a);
    return 0;
}
