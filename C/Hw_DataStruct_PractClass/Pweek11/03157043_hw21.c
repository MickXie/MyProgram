#include <stdio.h>

int n;
int adj[1000][1000];
int visited[1000];

void dfs(int u)
{
    visited[u] = 1;
    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && !visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("1\n");
    return 0;
}
