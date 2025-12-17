#include <stdio.h>
#include <stdlib.h>

#define MAXV 20

typedef struct Node
{
    int v;
    struct Node *next;
} Node;

Node *adjList[MAXV];
int visited[MAXV];
int maxV = -1;

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
    printf("%d ", u);

    Node *cur = adjList[u];
    while (cur != NULL)
    {
        int v = cur->v;
        if (!visited[v])
            dfs(v);
        cur = cur->next;
    }
}

int main(void)
{
    int u, v;
    for (int i = 0; i < MAXV; i++)
        adjList[i] = NULL;

    while (scanf("%d %d", &u, &v) == 2)
    {
        addEdge(u, v);
        addEdge(v, u);
        if (u > maxV)
            maxV = u;
        if (v > maxV)
            maxV = v;
    }

    for (int i = 0; i <= maxV; i++)
    {
        if (!visited[i] && adjList[i] != NULL)
        {
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}
