#include <stdio.h>
#include <string.h>
#define MAX_TERMS 1001
typedef struct
{
    int degree;
    int coef[MAX_TERMS];
} poly;
bubble_sort(poly ans)
{
    int count = ans.degree;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ans.coef[j] < ans.coef[j + 1])
            {
                int tmpc = ans.coef[j];
                ans.coef[j] = ans.coef[j + 1];
                ans.coef[j + 1] = tmpc;
            }
        }
    }
}
int main()
{
    poly a[MAX_TERMS], ans;
    int count = 0;
    while (scanf("%d", &a[count].degree) != EOF)
    {
        for (int i = 0; i < a[count].degree; i++)
            scanf("%d", &a[count].coef[i]);
        count++;
    }

    return 0;
}