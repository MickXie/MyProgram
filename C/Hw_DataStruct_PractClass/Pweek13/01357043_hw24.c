#include <stdio.h>
#include <stdlib.h>

#define MAXV 50

typedef struct Node
{
    int v;
    struct Node *next;
} Node;

Node *adj[MAXV];
int dfn[MAXV], low[MAXV];
int isArt[MAXV];
int timer = 0;
int maxV = -1;

void addEdge(int u, int v)
{
    Node *a = (Node *)malloc(sizeof(Node));
    a->v = v;
    a->next = adj[u];
    adj[u] = a;

    Node *b = (Node *)malloc(sizeof(Node));
    b->v = u;
    b->next = adj[v];
    adj[v] = b;
}

void dfs(int u, int parent)
{
    dfn[u] = low[u] = ++timer;
    int childCount = 0;

    for (Node *p = adj[u]; p; p = p->next)
    {
        int v = p->v;
        if (dfn[v] == 0)
        {
            childCount++;
            dfs(v, u);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent != -1 && low[v] >= dfn[u])
                isArt[u] = 1;
        }
        else if (v != parent)
        {
            low[u] = (low[u] < dfn[v]) ? low[u] : dfn[v];
        }
    }
    if (parent == -1 && childCount >= 2)
        isArt[u] = 1;
}

int main(void)
{
    int u, v;
    for (int i = 0; i < MAXV; i++)
    {
        adj[i] = NULL;
        dfn[i] = 0;
        low[i] = 0;
        isArt[i] = 0;
    }
    while (scanf("%d %d", &u, &v) == 2)
    {
        addEdge(u, v);
        if (u > maxV)
            maxV = u;
        if (v > maxV)
            maxV = v;
    }
    for (int i = 0; i <= maxV; i++)
        if (dfn[i] == 0 && adj[i] != NULL)
            dfs(i, -1);
    for (int i = 0; i <= maxV; i++)
        if (isArt[i])
            printf("%d ", i);
    printf("\n");

    return 0;
}
