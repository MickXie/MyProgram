#include <stdio.h>
#include <limits.h>

#define MAXV 100
#define INF 1000000000

int graph[MAXV][MAXV];
int dist[MAXV];
int visited[MAXV];

void init_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}

void dijkstra(int s, int n)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int minDist = INF;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main()
{
    int s;
    int u, v, w;
    int maxVertex = 0;

    if (scanf("%d", &s) != 1)
        return 0;

    init_graph(MAXV);

    while (scanf("%d %d %d", &u, &v, &w) == 3)
    {
        graph[u][v] = w;
        if (u > maxVertex)
            maxVertex = u;
        if (v > maxVertex)
            maxVertex = v;
    }

    int n = maxVertex + 1;

    dijkstra(s, n);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}
