#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N] = {
    {8, 0, 7, 1, 5, 4, 0, 9, 6},
    {9, 0, 5, 0, 2, 7, 1, 0, 8},
    {0, 4, 1, 0, 8, 0, 7, 0, 2},
    {5, 9, 0, 4, 0, 8, 2, 7, 1},
    {4, 0, 2, 5, 1, 3, 0, 8, 9},
    {6, 1, 0, 0, 7, 2, 0, 3, 5},
    {0, 8, 6, 2, 3, 5, 0, 1, 4},
    {1, 5, 4, 7, 9, 6, 8, 0, 3},
    {2, 3, 9, 8, 4, 1, 5, 6, 0}};

bool isSafe(int row, int col, int num)
{
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + boxStartRow][j + boxStartCol] == num)
                return false;

    return true;
}

bool solveSudoku()
{
    int row = -1, col = -1;
    bool empty = false;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == UNASSIGNED)
            {
                row = i;
                col = j;
                empty = true;
                break;
            }

    if (!empty)
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku())
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main()
{
    if (solveSudoku())
        printGrid();
    else
        printf("No solution exists!");
    return 0;
}
