#include <stdio.h>

void backtrack(int *s, int n, int index, int *subset, int subsetSize)
{
    if (index == n)
    {
        if (subsetSize == 0)
            printf("{ EMPTY-SET }\n");
        else
        {
            for (int i = 0; i < subsetSize; i++)
            {
                printf("%d ", subset[i]);
            }
            printf("\n");
        }
        return;
    }
    // 不選 s[index]
    backtrack(s, n, index + 1, subset, subsetSize);

    // 選 s[index]
    subset[subsetSize] = s[index];
    backtrack(s, n, index + 1, subset, subsetSize + 1);
}

int main()
{
    int l;
    printf("Enter size: ");
    scanf("%d", &l);
    int n[l];
    printf("Enter %d elements:\n", l);
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &n[i]);
    }

    int subset[l];
    printf("All subsets:\n");
    backtrack(n, l, 0, subset, 0);

    return 0;
}
