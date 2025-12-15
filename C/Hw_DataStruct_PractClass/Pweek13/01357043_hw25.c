#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 1000
#define INF 1000000000

int graph[MAXV][MAXV];
int visited[MAXV];
int parent[MAXV];
int key[MAXV];

typedef struct
{
    int a, b; // (parent, child)
} Edge;

int edgeCmp(const void *p1, const void *p2)
{
    const Edge *e1 = (const Edge *)p1;
    const Edge *e2 = (const Edge *)p2;
    if (e1->a != e2->a)
        return e1->a - e2->a;
    return e1->b - e2->b;
}

int main()
{
    int start;
    int u, v, w;
    int maxVertex = -1;

    /* 初始化圖 */
    for (int i = 0; i < MAXV; i++)
        for (int j = 0; j < MAXV; j++)
            graph[i][j] = INF;

    if (scanf("%d", &start) != 1)
        return 0;

    /* 讀邊直到 EOF */
    while (scanf("%d %d %d", &u, &v, &w) == 3)
    {
        if (w < graph[u][v])
        { /* 若重複邊，保留較小權重 */
            graph[u][v] = graph[v][u] = w;
        }
        if (u > maxVertex)
            maxVertex = u;
        if (v > maxVertex)
            maxVertex = v;
    }

    int V = maxVertex + 1;

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    key[start] = 0;

    /* Prim */
    for (int count = 0; count < V; count++)
    {
        int min = INF, u_min = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u_min = i;
            }
        }
        if (u_min == -1)
            break; /* 不連通就停止 */

        visited[u_min] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u_min][v] < key[v])
            {
                key[v] = graph[u_min][v];
                parent[v] = u_min;
            }
        }
    }

    /* 收集 MST 邊、算 cost */
    Edge edges[MAXV];
    int m = 0;
    int totalCost = 0;

    for (int i = 0; i < V; i++)
    {
        if (parent[i] != -1)
        {
            edges[m].a = parent[i];
            edges[m].b = i;
            totalCost += graph[parent[i]][i];
            m++;
        }
    }

    /* 排序後輸出（符合範例） */
    qsort(edges, m, sizeof(Edge), edgeCmp);

    for (int i = 0; i < m; i++)
    {
        printf("(%d %d) ", edges[i].a, edges[i].b);
    }
    printf("\n%d\n", totalCost);

    return 0;
}
