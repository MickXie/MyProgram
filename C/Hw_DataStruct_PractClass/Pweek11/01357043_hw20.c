#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u, v;
    int maxVertex = -1;
    int edges[1000][2];
    int edgeCount = 0;

    while (scanf("%d %d", &u, &v) == 2)
    {
        edges[edgeCount][0] = u;
        edges[edgeCount][1] = v;
        edgeCount++;

        if (u > maxVertex)
            maxVertex = u;
        if (v > maxVertex)
            maxVertex = v;
    }

    int n = maxVertex + 1;

    int matrix[100][100] = {0};
    for (int i = 0; i < edgeCount; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    int list[100][100];
    int listSize[100] = {0};

    for (int i = 0; i < edgeCount; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        list[u][listSize[u]++] = v;
        list[v][listSize[v]++] = u;
    }

    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < listSize[i]; a++)
        {
            for (int b = a + 1; b < listSize[i]; b++)
            {
                if (list[i][a] > list[i][b])
                {
                    int temp = list[i][a];
                    list[i][a] = list[i][b];
                    list[i][b] = temp;
                }
            }
        }
    }

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    printf("Adjacency list:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < listSize[i]; j++)
        {
            printf(" %d ->", list[i][j]);
        }
        printf(" end\n");
    }
    return 0;
}
