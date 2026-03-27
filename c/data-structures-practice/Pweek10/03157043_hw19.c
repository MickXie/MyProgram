#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

Node *modifiedSearch(Node *root, int key)
{
    Node *parent = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (key == curr->key)
            return curr;
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return parent;
}

void insert(int key)
{
    Node *parent = modifiedSearch(root, key);

    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->key = key;
        root->left = root->right = NULL;
        return;
    }

    if (parent->key == key)
        return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

void preorder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

int main(void)
{
    int n, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    return 0;
}
