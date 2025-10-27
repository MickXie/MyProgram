#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buildfail(const char *pattern, int *fail)
{
    int m = strlen(pattern);
    fail[0] = 0;
    int i = 1, prefix_len = 0;

    while (i < m)
    {
        if (pattern[prefix_len] == pattern[i])
        {
            prefix_len++;
            fail[i] = prefix_len;
            i++;
        }
        else
        {
            if (prefix_len != 0)
            {
                prefix_len = fail[prefix_len - 1];
            }
            else
            {
                fail[i] = 0;
                i++;
            }
        }
    }
}

int KMP(const char *text, const char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int *fail = (int *)malloc(sizeof(int) * m);

    buildfail(pattern, fail);

    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
                j = fail[j - 1];
            else
                i++;
        }

        if (j == m)
        {
            free(fail);
            return i - j; // match found
        }
    }

    free(fail);
    return -1; // not found
}

int main()
{
    char text[1000], pattern[1000];
    scanf("%s", text);
    scanf("%s", pattern);

    int pos = KMP(text, pattern);
    printf("%d\n", pos);

    return 0;
}
