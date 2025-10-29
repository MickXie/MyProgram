#include <stdio.h>
#include <string.h>
#define MAX_TERMS 101
typedef struct
{
    int col;
    int row;
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
    for (int i = 1; i <= a[0].value; i++)
        row_terms[a[i].row]++;
    for (int i = 1; i < a[0].row; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    for (int i = 1; i <= a[0].value; i++)
    {
        int j = starting_pos[a[i].row]++;
        b[j + 1].col = a[i].row;          
        b[j + 1].row = a[i].col;
        b[j + 1].value = a[i].value;
    }
}
int main()
{
    term a[MAX_TERMS], b[MAX_TERMS];
    scanf("%d", &a[0].col);
    scanf("%d", &a[0].row);
    scanf("%d", &a[0].value);
    for (int i = 0; i < a[0].value; i++)
    {
        scanf("%d", &a[i + 1].col);
        scanf("%d", &a[i + 1].row);
        scanf("%d", &a[i + 1].value);
    }
    fast_transpose(a, b);
    for (int i = 0; i <= b[0].value; i++)
        printf("%d %d %d\n", b[i].col, b[i].row, b[i].value);
    return 0;
}
