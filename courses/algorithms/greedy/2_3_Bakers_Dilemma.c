#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, s, idx;
} Job;

int cmp(const void *a, const void *b) {
    const Job *ja = (const Job *)a;
    const Job *jb = (const Job *)b;
    /* Sort by s/d descending: sa/da > sb/db <=> sa*db > sb*da */
    long long lhs = (long long)ja->s * jb->d;
    long long rhs = (long long)jb->s * ja->d;
    if (lhs != rhs) return (lhs > rhs) ? -1 : 1;
    /* Tie-break: smaller index first (lexicographic order) */
    return ja->idx - jb->idx;
}

int main() {
    int n;
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].d, &jobs[i].s);
        jobs[i].idx = i + 1;
    }

    qsort(jobs, n, sizeof(Job), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ", jobs[i].idx);
    }
    printf("\n");

    free(jobs);
    return 0;
}
