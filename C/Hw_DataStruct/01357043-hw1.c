#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *nums = NULL;
    size_t cap = 0, len = 0;
    double v;

    printf("(Enter any non-numeric word or character to start the calculation.)\n");

    while (scanf("%lf", &v) == 1)
    {
        if (len == cap)
        {
            cap = cap ? cap * 2 : 8;
            double *tmp = (double *)realloc(nums, cap * sizeof(double));
            if (!tmp)
            {
                free(nums);
                return 1;
            }
            nums = tmp;
        }
        nums[len++] = v;
    }

    if (len < 2)
    {
        fprintf(stderr, "Error: need coefficients and x.\n");
        free(nums);
        return 1;
    }

    double x = nums[len - 1];
    double result = nums[0];

    for (size_t i = 1; i < len - 1; ++i)
    {
        result = result * x + nums[i];
    }

    printf("\n%.10g\n", result);

    free(nums);
    return 0;
}