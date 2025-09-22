#include <stdio.h>
int sum(int n);
int main()
{
    int number, result;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    result = sum(number);
    printf("sum = %d", result);
    return 0;
}
int sum(int n)
{
    if (n >= 2)
    {
        // sum() function calls itself
        return sum(n - 1) + sum(n - 2);
    }

    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}