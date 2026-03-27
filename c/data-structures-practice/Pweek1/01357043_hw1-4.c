#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool palindrome(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len - 1 - i])
            return false;
    return true;
}

int main()
{
    char *test;
    scanf("%s", test);
    if (palindrome(test))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
