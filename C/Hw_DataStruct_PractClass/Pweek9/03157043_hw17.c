#include <stdio.h>
#include <string.h>

#define MAXN 20
#define MAXSIZE 256

typedef struct
{
    int mid;
    int left;
    int right;
} Node;

Node list[MAXN];
int tree[MAXSIZE];

int maxIndex;
int findNode(int x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (list[i].mid == x)
            return i;
    }
    return 0;
}
void preorder(int root, int n)
{
    if (root == 0)
        return;
    printf("%d ", root);
    int id = findNode(root, n);
    preorder(list[id].left, n);
    preorder(list[id].right, n);
}

void inorder(int root, int n)
{
    if (root == 0)
        return;
    int id = findNode(root, n);
    inorder(list[id].left, n);
    printf("%d ", root);
    inorder(list[id].right, n);
}

void postorder(int root, int n)
{
    if (root == 0)
        return;
    int id = findNode(root, n);
    postorder(list[id].left, n);
    postorder(list[id].right, n);
    printf("%d ", root);
}

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        memset(tree, 0, sizeof(tree));
        maxIndex = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d %d",
                  &list[i].mid,
                  &list[i].left,
                  &list[i].right);
        }

        int root = list[1].mid;

        inorder(root, n);
        printf("\n");

        preorder(root, n);
        printf("\n");

        postorder(root, n);
        printf("\n");
    }

    return 0;
}
