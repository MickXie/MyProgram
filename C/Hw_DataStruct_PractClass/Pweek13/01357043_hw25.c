#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define INF 1000000000

typedef struct Node
{
    int v;
    int w;
    struct Node *next;
} Node;

typedef struct
{
    int u, v;
} Edge;

Node *adj[MAXV];
int inMST[MAXV];
int key[MAXV];
int parent[MAXV];
int maxV = -1;

void addEdge(int u, int v, int w)
{
    Node *a = (Node *)malloc(sizeof(Node));
    a->v = v;
    a->w = w;
    a->next = adj[u];
    adj[u] = a;

    Node *b = (Node *)malloc(sizeof(Node));
    b->v = u;
    b->w = w;
    b->next = adj[v];
    adj[v] = b;
}

void prim(int start)
{
    for (int i = 0; i <= maxV; i++)
    {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = 0;
    }

    key[start] = 0;

    for (int count = 0; count <= maxV; count++)
    {
        int u = -1;
        int minKey = INF;

        for (int i = 0; i <= maxV; i++)
            if (!inMST[i] && key[i] < minKey)
            {
                minKey = key[i];
                u = i;
            }

        if (u == -1)
            break;

        inMST[u] = 1;

        for (Node *p = adj[u]; p; p = p->next)
        {
            int v = p->v;
            int w = p->w;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
}

void bubbleSort(Edge edges[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (edges[j].u > edges[j + 1].u ||
                (edges[j].u == edges[j + 1].u &&
                 edges[j].v > edges[j + 1].v))
            {
                Edge tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }
}

int main(void)
{
    int start;
    scanf("%d", &start);

    for (int i = 0; i < MAXV; i++)
        adj[i] = NULL;

    int u, v, w;
    while (scanf("%d %d %d", &u, &v, &w) == 3)
    {
        addEdge(u, v, w);
        if (u > maxV)
            maxV = u;
        if (v > maxV)
            maxV = v;
    }

    prim(start);

    Edge edges[MAXV];
    int edgeCnt = 0;
    int totalCost = 0;

    for (int i = 0; i <= maxV; i++)
    {
        if (parent[i] != -1)
        {
            edges[edgeCnt].u = parent[i];
            edges[edgeCnt].v = i;
            edgeCnt++;
            totalCost += key[i];
        }
    }

    bubbleSort(edges, edgeCnt);

    for (int i = 0; i < edgeCnt; i++)
    {
        printf("(%d %d)", edges[i].u, edges[i].v);
        if (i < edgeCnt - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d\n", totalCost);

    return 0;
}
