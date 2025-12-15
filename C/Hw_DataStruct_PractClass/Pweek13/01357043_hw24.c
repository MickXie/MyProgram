#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 1000

typedef struct Node
{
    int v;
    struct Node *next;
} Node;

Node *adj[MAXV];
int disc[MAXV], low[MAXV], parent[MAXV];
int visited[MAXV], isAP[MAXV];
int timeCounter;
int maxVertex = 0;

/* 新增邊 */
void addEdge(int u, int v)
{
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->v = v;
    n1->next = adj[u];
    adj[u] = n1;

    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->v = u;
    n2->next = adj[v];
    adj[v] = n2;
}

/* DFS + Tarjan */
void dfs(int u)
{
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (Node *p = adj[u]; p; p = p->next)
    {
        int v = p->v;

        if (!visited[v])
        {
            children++;
            parent[v] = u;
            dfs(v);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            /* 非 root */
            if (parent[u] != -1 && low[v] >= disc[u])
                isAP[u] = 1;

            /* root */
            if (parent[u] == -1 && children > 1)
                isAP[u] = 1;
        }
        else if (v != parent[u])
        {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int main()
{
    int u, v;

    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    memset(isAP, 0, sizeof(isAP));

    /* 讀入邊直到 EOF */
    while (scanf("%d %d", &u, &v) == 2)
    {
        addEdge(u, v);
        if (u > maxVertex)
            maxVertex = u;
        if (v > maxVertex)
            maxVertex = v;
    }

    for (int i = 0; i <= maxVertex; i++)
        parent[i] = -1;

    /* 處理不連通圖 */
    for (int i = 0; i <= maxVertex; i++)
    {
        if (!visited[i] && adj[i])
            dfs(i);
    }

    /* 輸出割點 */
    for (int i = 0; i <= maxVertex; i++)
    {
        if (isAP[i])
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
