#include <stdio.h>
#include <string.h>
#define MAXN 20
typedef struct
{
    int x, y, z;
} Node;
Node list[MAXN];
int n;
int find(int val)
{
    for (int i = 1; i <= n; i++)
        if (list[i].x == val)
            return i;
    return 0;
}
void inorder(int val)
{
    if (val == 0)
        return;
    int idx = find(val);
    inorder(list[idx].y);
    printf("%d ", val);
    inorder(list[idx].z);
}
void preorder(int val)
{
    if (val == 0)
        return;
    int idx = find(val);
    printf("%d ", val);
    preorder(list[idx].y);
    preorder(list[idx].z);
}
void postorder(int val)
{
    if (val == 0)
        return;
    int idx = find(val);
    postorder(list[idx].y);
    postorder(list[idx].z);
    printf("%d ", val);
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d %d %d", &list[i].x, &list[i].y, &list[i].z);
        int root = list[1].x;
        inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }
    return 0;
}
