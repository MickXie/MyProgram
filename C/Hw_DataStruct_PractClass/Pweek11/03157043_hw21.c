#include <stdio.h>
#include <stdlib.h>

#define MAXN 20

typedef struct Node
{
    int v;
    struct Node *next;
} Node;

int n;
int matrix[MAXN][MAXN];
Node *adjList[MAXN];
int visited[MAXN];

void addEdge(int u, int v)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->v = v;
    node->next = adjList[u];
    adjList[u] = node;
}

void dfs(int u)
{
    visited[u] = 1;
    Node *cur = adjList[u];
    while (cur != NULL)
    {
        int v = cur->v;
        if (!visited[v])
            dfs(v);
        cur = cur->next;
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                addEdge(i, j);
                addEdge(j, i);
            }
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
