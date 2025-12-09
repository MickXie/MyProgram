#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000

int graph[MAXV][MAXV];
int visited[MAXV];
int vertexUsed[MAXV];
int maxVertex = -1;

void DFS(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i <= maxVertex; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int u, v;
    for (int i = 0; i < MAXV; i++)
    {
        visited[i] = 0;
        vertexUsed[i] = 0;
        for (int j = 0; j < MAXV; j++)
            graph[i][j] = 0;
    }
    while (scanf("%d %d", &u, &v) == 2)
    {
        graph[u][v] = 1;
        graph[v][u] = 1;
        vertexUsed[u] = vertexUsed[v] = 1;
        if (u > maxVertex)
            maxVertex = u;
        if (v > maxVertex)
            maxVertex = v;
    }
    for (int i = 0; i <= maxVertex; i++)
    {
        if (vertexUsed[i] && !visited[i])
        {
            DFS(i);
            printf("\n");
        }
    }
    return 0;
}
