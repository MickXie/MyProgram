#include <stdio.h>
#include <string.h>

#define MAX 1000

void buildFailure(char *pattern, int fail[])
{
    int m = strlen(pattern);
    fail[0] = -1;
    int j = -1;
    for (int i = 1; i < m; i++)
    {
        while (j >= 0 && pattern[j + 1] != pattern[i])
        {
            j = fail[j];
        }
        if (pattern[j + 1] == pattern[i])
        {
            j++;
        }
        fail[i] = j;
    }
}

int KMP(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int fail[MAX];
    buildFailure(pattern, fail);
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        while (j >= 0 && pattern[j + 1] != text[i])
        {
            j = fail[j];
        }
        if (pattern[j + 1] == text[i])
        {
            j++;
        }
        if (j == m - 1)
        {
            return i - m + 2;
        }
    }
    return -1;
}

int main()
{
    char text[MAX], pattern[MAX];
    scanf("%s", text);
    scanf("%s", pattern);
    int pos = KMP(text, pattern);
    printf("%d\n", pos - 1);
    return 0;
}
