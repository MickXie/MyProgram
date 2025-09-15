#include <stdio.h>
int sum(int n1, int n2);
int main()
{
    int number1, result, number2;
    printf("Enter a positive integer: ");
    scanf("%d", &number1);
    printf("Enter a positive integer: ");
    scanf("%d", &number2);
    result = sum(number1, number2);
    printf("sum = %d", result);
    return 0;
}
int sum(int n1, int n2)
{
    if (n2 > 0)
        // sum() function calls itself
        return n1 * sum(n1, n2 - 1);
    else
        return 1;
}