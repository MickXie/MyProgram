#include <stdio.h>
#include <string.h>
#define MAX_TERMS 101
typedef struct
{
    int col;
    int row;
    int value;
} term;
void Sum(poly a[100], int n[100], int t)
{
    poly ans = {0};
    int anst = 0;

    // 收集所有項目
    for (int i = 0; i < t; i++)
    {
        for (int k = 0; k < n[i]; k++)
        {
            ans.degree[anst] = a[i].degree[k];
            ans.coef[anst] = a[i].coef[k];
            anst++;
        }
    }

    // 依次方由大到小排序 (bubble sort)
    for (int i = 0; i < anst - 1; i++)
    {
        for (int j = i + 1; j < anst; j++)
        {
            if (ans.degree[i] < ans.degree[j])
            {
                int tmpd = ans.degree[i];
                ans.degree[i] = ans.degree[j];
                ans.degree[j] = tmpd;

                int tmpc = ans.coef[i];
                ans.coef[i] = ans.coef[j];
                ans.coef[j] = tmpc;
            }
        }
    }
    poly merged = {0};
    int mt = 0;
    for (int i = 0; i < anst; i++)
    {
        if (mt > 0 && ans.degree[i] == merged.degree[mt - 1])
        {
            // 同次方 -> 係數相加
            merged.coef[mt - 1] += ans.coef[i];
        }
        else
        {
            // 新的次方
            merged.degree[mt] = ans.degree[i];
            merged.coef[mt] = ans.coef[i];
            mt++;
        }
    }

    // 輸出（排除係數為 0 的項）
    int count = 0;
    for (int i = 0; i < mt; i++)
    {
        if (merged.coef[i] != 0)
            count++;
    }
    printf("%d\n", count);
    for (int i = 0; i < mt; i++)
    {
        if (merged.coef[i] != 0)
            printf("%d ", merged.coef[i]);
    }
    printf("\n");
    for (int i = 0; i < mt; i++)
    {
        if (merged.coef[i] != 0)
            printf("%d ", merged.degree[i]);
    }
    printf("\n");
}

int main()
{
    term a[MAX_TERMS];
    int n[100], t = 0;

    while (scanf("%d", &n[t]) != EOF)
    {
        for (int i = 0; i < n[t]; i++)
            scanf("%d", &a[t].coef[i]);
        for (int i = 0; i < n[t]; i++)
            scanf("%d", &a[t].degree[i]);
        t++;
    }

    Sum(a, n, t);
    return 0;
}
