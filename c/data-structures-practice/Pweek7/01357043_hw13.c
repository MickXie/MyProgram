#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *newNode(int v)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;
    return n;
}

int main()
{
    int x, v;
    Node *head = NULL, *tail = NULL;

    // 先讀全部數字，最後一個是 x
    int nums[1000], n = 0;
    while (scanf("%d", &v) == 1)
        nums[n++] = v;
    if (n == 0)
        return 0;
    x = nums[n - 1];
    n--;

    // 建立 linked list
    for (int i = 0; i < n; i++)
    {
        Node *tmp = newNode(nums[i]);
        if (!head)
            head = tail = tmp;
        else
            tail = tail->next = tmp;
    }

    // 分成兩段
    Node *lessH = NULL, *lessT = NULL, *geH = NULL, *geT = NULL;
    for (Node *cur = head; cur; cur = cur->next)
    {
        if (cur->val < x)
        {
            if (!lessH)
                lessH = lessT = cur;
            else
                lessT = lessT->next = cur;
        }
        else
        {
            if (!geH)
                geH = geT = cur;
            else
                geT = geT->next = cur;
        }
    }

    if (lessT)
        lessT->next = geH;
    if (geT)
        geT->next = NULL;

    Node *ans = lessH ? lessH : geH;
    for (Node *cur = ans; cur; cur = cur->next)
    {
        printf("%d", cur->val);
        if (cur->next)
            printf(" ");
    }
    return 0;
}
