#include <stdio.h>
#include <stdlib.h>

/* Min-heap */
typedef struct {
    long long *data;
    int size;
    int capacity;
} Heap;

void heap_push(Heap *h, long long val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (long long *)realloc(h->data, h->capacity * sizeof(long long));
    }
    int i = h->size++;
    h->data[i] = val;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent] > h->data[i]) {
            long long tmp = h->data[parent];
            h->data[parent] = h->data[i];
            h->data[i] = tmp;
            i = parent;
        } else break;
    }
}

long long heap_pop(Heap *h) {
    long long ret = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left  < h->size && h->data[left]  < h->data[smallest]) smallest = left;
        if (right < h->size && h->data[right] < h->data[smallest]) smallest = right;
        if (smallest == i) break;
        long long tmp = h->data[i];
        h->data[i] = h->data[smallest];
        h->data[smallest] = tmp;
        i = smallest;
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        Heap h;
        h.capacity = n + 1;
        h.size = 0;
        h.data = (long long *)malloc(h.capacity * sizeof(long long));

        for (int i = 0; i < n; i++) {
            long long x;
            scanf("%lld", &x);
            heap_push(&h, x);
        }

        long long total_cost = 0;
        while (h.size > 1) {
            long long a = heap_pop(&h);
            long long b = heap_pop(&h);
            long long s = a + b;
            total_cost += s;
            heap_push(&h, s);
        }

        printf("%lld\n", total_cost);
        free(h.data);
    }

    return 0;
}
