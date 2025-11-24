#include <stdio.h>
#include <string.h>

#define MAX 10000

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void insert(int x)
{
    heap[++heapSize] = x;
    int i = heapSize;
    while (i > 1 && heap[i] > heap[i / 2])
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}
int deleteMax(void)
{
    if (heapSize == 0)
        return -1;

    int maxVal = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        if (left > heapSize)
            break; // 沒有子節點

        int largerChild = left;
        if (right <= heapSize && heap[right] > heap[left])
            largerChild = right;

        if (heap[i] >= heap[largerChild])
            break;

        swap(&heap[i], &heap[largerChild]);
        i = largerChild;
    }
    return maxVal;
}

int main(void)
{
    char line[10000];
    if (fgets(line, sizeof(line), stdin) != NULL)
    {
        char *p = strtok(line, " \t\r\n");
        while (p != NULL)
        {
            int x;
            sscanf(p, "%d", &x);
            insert(x);
            p = strtok(NULL, " \t\r\n");
        }
    }
    int k;
    if (scanf("%d", &k) == 1)
    {
        for (int i = 0; i < k; i++)
            deleteMax();
    }
    for (int i = 1; i <= heapSize; i++)
    {
        printf("(%d, %d)", i, heap[i]);
        if (i < heapSize)
            printf(" ");
    }
    printf("\n");

    return 0;
}
