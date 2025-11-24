#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
Node *modifiedSearch(Node *root, int key)
{
    Node *parent = NULL;
    Node *cur = root;

    while (cur != NULL)
    {
        parent = cur;

        if (key == cur->key)
            return NULL;
        else if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return parent;
}
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    Node *p = modifiedSearch(root, key);
    if (p == NULL)
        return root;

    if (key < p->key)
        p->left = newNode(key);
    else
        p->right = newNode(key);

    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    return 0;
}
