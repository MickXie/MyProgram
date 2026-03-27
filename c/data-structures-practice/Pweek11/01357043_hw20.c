#include <stdio.h>
#include <string.h>

#define MAXV 100

int main(void)
{
    int adj[MAXV][MAXV];
    int u, v;
    int maxV = -1;

    memset(adj, 0, sizeof(adj));

    while (scanf("%d %d", &u, &v) == 2)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
        if (u > maxV)
            maxV = u;
        if (v > maxV)
            maxV = v;
    }

    int n = maxV + 1;

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", adj[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Adjacency list:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j])
                printf(" %d ->", j);
        }
        printf(" end\n");
    }

    return 0;
}
