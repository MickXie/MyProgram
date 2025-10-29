#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define Max 100
typedef struct poly Poly;
struct poly
{
    float coef;
    int expon;
};
void Polynomial_Addition(Poly A[], Poly B[], Poly ans[])
{
    int a = A[0].expon, b = B[0].expon;
    int i = 1, j = 1, count = 1;

    while (i <= a && j <= b)
    {
        if (A[i].expon > B[j].expon)
            ans[count++] = A[i++];
        else if (A[i].expon < B[j].expon)
            ans[count++] = B[j++];
        else
        {
            float sum = A[i].coef + B[j].coef;
            if (sum != 0)
            {
                ans[count].coef = sum;
                ans[count].expon = A[i].expon;
                count++;
            }
            i++;
            j++;
        }
    }
    while (i <= a)
        ans[count++] = A[i++];
    while (j <= b)
        ans[count++] = B[j++];
    ans[0].expon = count - 1;
}
void Polynomial_Multiplication(Poly A[], Poly B[], Poly ans[])
{
    int a = A[0].expon, b = B[0].expon;
    Poly temp[Max], result[Max];
    result[0].expon = 0; // 結果初始化
    result[1].coef = 0;
    result[1].expon = 0;

    // 逐項相乘後加總
    for (int i = 1; i <= a; i++)
    {
        int count = 1;
        for (int j = 1; j <= b; j++)
        {
            temp[count].coef = A[i].coef * B[j].coef;
            temp[count].expon = A[i].expon + B[j].expon;
            count++;
        }
        temp[0].expon = count - 1; // 暫存項數
        Polynomial_Addition(result, temp, ans);
        for (int k = 0; k <= ans[0].expon; k++)
            result[k] = ans[k]; // 更新結果
    }
}

int main()
{
    int count = 0;
    int n;
    Poly P[10][Max], ans[Max];
    while (1)
    {
        if (scanf("%d", &n) == EOF)
            break;
        P[count][0].expon = n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%f", &P[count][i].coef);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &P[count][i].expon);
        }
        count++;
    }
    Poly temp[Max];
    Polynomial_Multiplication(P[0], P[1], ans);
    for (int i = 2; i < count; i++)
    {
        Polynomial_Multiplication(ans, P[i], temp); // ✅ 先把結果放進 temp
        for (int k = 0; k <= temp[0].expon; k++)    // ✅ 再複製回 ans
            ans[k] = temp[k];
    }
    printf("%d\n", ans[0].expon);
    for (int i = 1; i <= ans[0].expon; i++)
        printf("%.0f ", ans[i].coef);
    printf("\n");
    for (int i = 1; i <= ans[0].expon; i++)
        printf("%d ", ans[i].expon);
    printf("\n");
}