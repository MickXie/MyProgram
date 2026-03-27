#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200 /* maximum heap size+1 */
int heap_full(int n)
{
    return n == MAX_ELEMENTS - 1;
}

int heap_empty(int n)
{
    return n == 0;
}

typedef struct
{
    int key;
    /* other fields */
} element;
element heap[MAX_ELEMENTS];
int n = 0;
void push(element item, int *n)
{
    /* insert item into a max heap of current size *n */
    int i;
    if (heap_full(*n))
    {
        printf("The heap is full. \n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}
int main()
{
}