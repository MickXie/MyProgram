#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}
void nineTimesNine(int n, int m)
{
    if (n > 9)
        return;

    printf("%d x %d = %2d\t", n, m, n * m);

    if (m < 9)
    {
        nineTimesNine(n, m + 1);
    }
    else
    {
        printf("\n");
        nineTimesNine(n + 1, 1);
    }
}
int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (1)
    {
        while (i <= right && arr[i] >= pivot)
            i++;
        while (j >= left && arr[j] < pivot)
            j--;
        if (i >= j)
            break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;
    return j;
}
void quickSort(int arr[], int left, int right)
{
    if (right > left)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}
int is_palindrome(char *string)
{
    char stack[100];            // 可以捨棄
    int total = strlen(string); // string要用strlen,j用不著,而且total所指的最後一個字是/0
    strcpy(stack, string);
    for (int i = 0; i < total / 2; i++)
    {
        if (!(stack[i] == string[total - 1 - i]))
            return 0;
    }
    return 1;
}
void homework1()
{
    char ans[100][10];
    char string[100]; // 要配置記憶體
    int count = 0;
    while (scanf("%s", string) != EOF)
    {
        int result = is_palindrome(string);  // 別硬轉
        sprintf(ans[count++], "%d", result); // 這樣轉比較好
    }
    for (int i = 0; i < count; i++)
        printf("%s\n", ans[i]);
}
void subset_recursive(int arr[], int n, int index, int current[], int cur_size)
{
    if (index == n)
    {
        if (cur_size == 0)
        {
            printf("Empty\n");
        }
        else
        {
            for (int i = 0; i < cur_size; i++)
            {
                printf("%d ", current[i]);
            }
            printf("\n");
        }
    }
    else
    {
        current[cur_size] = arr[index];
        subset_recursive(arr, n, index + 1, current, cur_size + 1);
        // 要這個index所指的元素了
        subset_recursive(arr, n, index + 1, current, cur_size);
        // 不要這個index所指的元素了
    }
}
typedef struct
{
    int index;
    int cur_size;
} Frame;
void subset_stack(int arr[], int n)
{
    Frame stack[100];
    int sp = 0;
    int current[100];
    stack[sp++] = (Frame){0, 0}; //= {0, 0};C 不合法（只能在宣告stack適時初始化）
    while (sp > 0)
    {
        Frame now = stack[--sp]; // 先減 1再用新值
        if (now.index == n)
        {
            if (now.cur_size == 0)
            {
                printf("empty\n");
            }
            else
            {
                for (int i = 0; i < now.cur_size; i++)
                {
                    printf("%d ", current[i]);
                }
                printf("\n");
            }
        }
        else
        {
            stack[sp++] = (Frame){now.index + 1, now.cur_size}; // 不要
            current[now.cur_size] = arr[now.index];
            stack[sp++] = (Frame){now.index + 1, now.cur_size + 1}; // 要
            // 原本這樣會讓「不選的情況」先被處理（順序顛倒）由於 stack 是「後進先出 (LIFO)」。
        }
    }
    // 分析遞迴 → Stack 模擬的思維流程
    // 1 找出遞迴函式裡會變的參數（就是要記錄的狀態）
    // 2 決定 base case 條件
    // 3 決定每層要 push 幾個新 frame（幾個分支）
    // 4 決定 push 順序（確保執行順序一致）
    // 5 在 while 迴圈中不斷 pop / 處理 / push
}
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

/*
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
    Polynomial_Addition(P[0], P[1], ans);
    for (int i = 2; i < count; i++)
    {
        Polynomial_Addition(ans, P[i], temp);    // ✅ 先把結果放進 temp
        for (int k = 0; k <= temp[0].expon; k++) // ✅ 再複製回 ans
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
*/


