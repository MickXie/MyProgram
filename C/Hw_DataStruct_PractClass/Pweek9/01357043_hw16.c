#include <stdio.h>
#include <string.h>

#define MAXN 20
#define MAXSIZE 300

typedef struct
{
    int x, y, z;
} Node;

Node list[MAXN];
int tree[MAXSIZE];

int find(int x, int n)
{
    for (int i = 1; i <= n; i++)
        if (list[i].x == x)
            return i;
    return 0;
}

void build(int rootVal, int pos, int n)
{
    if (rootVal == 0)
        return;
    tree[pos] = rootVal;
    int id = find(rootVal, n);

    if (id == 0)
        return;

    build(list[id].y, pos * 2, n);
    build(list[id].z, pos * 2 + 1, n);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {

        for (int i = 1; i <= n; i++)
            scanf("%d %d %d", &list[i].x, &list[i].y, &list[i].z);

        memset(tree, 0, sizeof(tree));

        int root = list[1].x;

        build(root, 1, n);
        int maxIndex = 1;
        for (int i = 1; i < MAXSIZE; i++)
            if (tree[i] != 0)
                maxIndex = i;
        for (int i = 1; i <= maxIndex; i++)
        {
            printf("%d", tree[i]);
            if (i != maxIndex)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
