#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int key)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
Node *buildTree(int arr[], int n, int index)
{
    if (index >= n || arr[index] == -1)
        return NULL;

    Node *root = newNode(arr[index]);
    root->left = buildTree(arr, n, 2 * index + 1);
    root->right = buildTree(arr, n, 2 * index + 2);
    return root;
}
Node *LCA(Node *root, int u, int v)
{
    if (!root)
        return NULL;

    if (u < root->key && v < root->key)
        return LCA(root->left, u, v);

    if (u > root->key && v > root->key)
        return LCA(root->right, u, v);

    return root;
}

int main()
{
    int arr[MAX];
    int n = 0;
    while (scanf("%d", &arr[n]) == 1)
    {
        n++;
        if (getchar() == '\n')
            break;
    }

    int u, v;
    scanf("%d %d", &u, &v);

    Node *root = buildTree(arr, n, 0);
    Node *lca = LCA(root, u, v);

    if (lca)
        printf("%d\n", lca->key);
    else
        printf("No LCA Found\n");

    return 0;
}
