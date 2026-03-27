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
void build(int rootVal, int pos, int n)
{
    if (rootVal == 0 || pos >= MAXSIZE)
        return;

    tree[pos] = rootVal;
    if (pos > maxIndex)
        maxIndex = pos;

    int id = findNode(rootVal, n);
    if (id == 0)
        return;

    build(list[id].left, pos * 2, n);
    build(list[id].right, pos * 2 + 1, n);
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

        build(list[1].mid, 1, n);
        for (int i = 1; i <= maxIndex; i++)
        {
            if (i > 1)
                printf(" ");
            printf("%d", tree[i]);
        }
        printf("\n");
    }

    return 0;
}
