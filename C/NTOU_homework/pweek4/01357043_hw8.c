#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

int isValid(int row, int col, int num)
{

    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num)
            return 0;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][col] == num)
            return 0;
    }

    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return 0;
        }
    }
    return 1;
}

int solveSudoku()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(row, col, num))
                    {
                        board[row][col] = num;
                        if (solveSudoku())
                            return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            for (int k = 0; k < 9; k++)
                printf("- ");
            printf("\n");
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\n");
    if (solveSudoku())
    {
        printBoard();
    }
    else
    {
        printf("No solution.\n");
    }
    return 0;
}
