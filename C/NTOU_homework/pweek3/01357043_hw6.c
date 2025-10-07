#include <stdio.h>
#include <string.h>
#define MAX_TERMS 101

typedef struct
{
    int row;
    int col;
    int value;
} term;

void fast_transpose(term a[], term b[])
{
    int row_terms[a[0].row];
    int starting_pos[a[0].row];
    memset(row_terms, 0, sizeof(row_terms));
    memset(starting_pos, 0, sizeof(starting_pos));

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    // 計算每一 row 的非零數量
    for (int i = 1; i <= a[0].value; i++)
        row_terms[a[i].row]++;

    // 計算起始位置
    starting_pos[0] = 1;
    for (int i = 1; i < a[0].row; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    // 把元素放進去
    for (int i = 1; i <= a[0].value; i++)
    {
        int j = starting_pos[a[i].row]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void mat_multiply(term a[], term bt[], term c[])
{
    if (a[0].col != bt[0].col) // 檢查相容性
    {
        c[0].row = 0;
        c[0].col = 0;
        c[0].value = 0;
        return;
    }

    c[0].row = a[0].row;
    c[0].col = bt[0].row; // bt 是 B 的轉置，所以 col = 原本的 col
    c[0].value = 0;

    int ct = 1; // c 的游標

    // 對 A 的每一 row
    for (int i = 0; i < a[0].row; i++)
    {
        // 對 B^T (即 B 的 col)
        for (int j = 0; j < bt[0].row; j++)
        {
            int sum = 0;

            // 掃描 A 的 row i
            for (int pa = 1; pa <= a[0].value; pa++)
            {
                if (a[pa].row != i)
                    continue;

                // 掃描 B^T 的 row j
                for (int pb = 1; pb <= bt[0].value; pb++)
                {
                    if (bt[pb].row != j)
                        continue;

                    // 比對 A.col 與 B.row
                    if (a[pa].col == bt[pb].col)
                        sum += a[pa].value * bt[pb].value;
                }
            }

            if (sum != 0)
            {
                c[ct].row = i;
                c[ct].col = j;
                c[ct].value = sum;
                ct++;
            }
        }
    }

    c[0].value = ct - 1; // 非零項數量
}

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS], bt[MAX_TERMS];
    scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    for (int i = 0; i < a[0].value; i++)
        scanf("%d %d %d", &a[i + 1].row, &a[i + 1].col, &a[i + 1].value);
    scanf("%d %d %d", &b[0].row, &b[0].col, &b[0].value);
    for (int i = 0; i < b[0].value; i++)
        scanf("%d %d %d", &b[i + 1].row, &b[i + 1].col, &b[i + 1].value);
    fast_transpose(b, bt);
    mat_multiply(a, bt, c);
    printf("%d %d %d\n", c[0].row, c[0].col, c[0].value);
    for (int i = 1; i <= c[0].value; i++)
        printf("%d %d %d\n", c[i].row, c[i].col, c[i].value);

    return 0;
}
