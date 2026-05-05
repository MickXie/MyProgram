#include <stdio.h>
#include <stdlib.h>

/* Global to avoid stack overflow for large N, W */
int c[2001][2001];
int items[2001][2001];

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    int g[2001], v[2001];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &g[i], &v[i]);
    }

    /* DP: c[i][j] = max value using first i stones with capacity j */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j - g[i] < 0)
            {
                c[i][j] = c[i - 1][j];
            }
            else
            {
                int take = c[i - 1][j - g[i]] + v[i];
                if (take > c[i - 1][j])
                {
                    c[i][j] = take;
                    items[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i - 1][j];
                }
            }
        }
    }

    printf("%d\n", c[n][w]);

    /* Backtrack: collect in descending order, then print ascending */
    int selected[2001], cnt = 0;
    for (int i = n, j = w; i >= 1; i--)
    {
        if (items[i][j])
        {
            selected[cnt++] = i;
            j -= g[i];
        }
    }
    for (int k = cnt - 1; k >= 0; k--)
    {
        printf("%d", selected[k]);
        if (k > 0)
            printf(" ");
    }
    printf("\n");

    return 0;
}
