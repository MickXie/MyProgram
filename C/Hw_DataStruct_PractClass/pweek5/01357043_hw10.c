#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STACK_SIZE 10000

typedef struct
{
    short int vert;
    short int horiz;
} offsets;

typedef struct
{
    short int row;
    short int col;
    short int dir;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

int maze[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];
offsets move[8] = {
    {-1, 0}, // N 0
    {-1, 1}, // NE 1
    {0, 1},  // E 2
    {1, 1},  // SE 3
    {1, 0},  // S 4
    {1, -1}, // SW 5
    {0, -1}, // W 6
    {-1, -1} // NW 7
};

void push(element item)
{
    stack[++top] = item;
}

element pop()
{
    return stack[top--];
}

void path(int n, int m, int start_row, int start_col, int exit_row, int exit_col)
{
    int found = 0;
    int row, col, next_row, next_col, dir, i;
    element position;

    mark[start_row][start_col] = 1;
    top = 0;
    stack[0].row = start_row;
    stack[0].col = start_col;
    stack[0].dir = 0;

    while (top > -1 && !found)
    {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found)
        {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;

            if (next_row == exit_row && next_col == exit_col)
            {
                found = 1;
            }
            else if (maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0)
            {
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = dir + 1;
                push(position);

                row = next_row;
                col = next_col;
                dir = 0;
            }
            else
            {
                dir++;
            }
        }
    }

    if (found)
    {
        // 印出 stack 內的路徑
        for (i = 0; i <= top; i++)
        {
            printf("(%d,%d) ", stack[i].row, stack[i].col);
        }
        printf("(%d,%d)\n", row, col);
        printf("(%d,%d)\n", exit_row, exit_col);
    }
    else
    {
        printf("None\n");
    }
}

int main()
{
    int n, m;
    int i, j;
    int start_row, start_col, exit_row, exit_col;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
            mark[i][j] = 0;
        }
    }
    scanf("%d %d %d %d", &start_row, &start_col, &exit_row, &exit_col);

    path(n, m, start_row, start_col, exit_row, exit_col);
    return 0;
}
