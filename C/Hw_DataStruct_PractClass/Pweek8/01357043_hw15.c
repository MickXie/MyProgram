#include <stdio.h>
#include <string.h>
int ok(int k, int m)
{
    int remain = 2 * k;
    int idx = 0;
    for (int killed = 0; killed < k; ++killed)
    {
        idx = (idx + m - 1) % remain;
        if (idx < k)
            return 0;
        remain--;
    }
    return 1;
}
int solve(int k)
{
    int m = k + 1;
    while (!ok(k, m))
        ++m;
    return m;
}
int main(void)
{
    int k, count = 0;
    char output[10][10];
    while (scanf("%d", &k) == 1 && k)
    {
        sprintf(output[count++], "%d", solve(k));
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", output[i]);
    }
    return 0;
}
