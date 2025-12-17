#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

Node *build(int arr[], int i, int n)
{
    if (i >= n || arr[i] == -1)
        return NULL;

    Node *root = (Node *)malloc(sizeof(Node));
    root->val = arr[i];
    root->left = build(arr, 2 * i + 1, n);
    root->right = build(arr, 2 * i + 2, n);
    return root;
}

int LCA(Node *root, int u, int v)
{
    if (!root)
        return -1;

    if (u < root->val && v < root->val)
        return LCA(root->left, u, v);
    else if (u > root->val && v > root->val)
        return LCA(root->right, u, v);
    else
        return root->val;
}

int main(void)
{
    int arr[100];
    int n = 0;
    char line[1024];
    if (fgets(line, sizeof(line), stdin) == NULL)
        return 0;
    char *p = strtok(line, " \t\r\n");
    while (p != NULL)
    {
        arr[n++] = atoi(p);
        p = strtok(NULL, " \t\r\n");
    }
    int u, v;
    scanf("%d %d", &u, &v);
    Node *root = build(arr, 0, n);
    printf("%d\n", LCA(root, u, v));
    return 0;
}
