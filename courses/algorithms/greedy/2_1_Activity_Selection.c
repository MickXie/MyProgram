#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int s, f;
} Activity;

int cmp(const void *a, const void *b) {
    return ((Activity *)a)->f - ((Activity *)b)->f;
}

int main() {
    int n;
    scanf("%d", &n);

    Activity *act = (Activity *)malloc(n * sizeof(Activity));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &act[i].s, &act[i].f);
    }

    qsort(act, n, sizeof(Activity), cmp);

    int count = 1;
    int last_finish = act[0].f;
    for (int i = 1; i < n; i++) {
        if (act[i].s >= last_finish) {
            count++;
            last_finish = act[i].f;
        }
    }

    printf("%d\n", count);

    free(act);
    return 0;
}
