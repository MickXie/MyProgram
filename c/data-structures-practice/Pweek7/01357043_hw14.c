#include <stdio.h>
#include <stdlib.h>

typedef struct Poly
{
    float coef;
    int exp;
    struct Poly *next;
} Poly;

Poly *newNode(float c, int e)
{
    Poly *n = (Poly *)malloc(sizeof(Poly));
    n->coef = c;
    n->exp = e;
    n->next = NULL;
    return n;
}

// Insert term into polynomial: keep order by descending exponent and combine like terms
void insertTerm(Poly **head, float c, int e)
{
    if (c == 0)
        return;
    Poly *cur = *head, *pre = NULL;
    while (cur && cur->exp > e)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur && cur->exp == e)
    {
        cur->coef += c;
        if (cur->coef == 0)
        {
            if (pre)
                pre->next = cur->next;
            else
                *head = cur->next;
            free(cur);
        }
    }
    else
    {
        Poly *node = newNode(c, e);
        if (pre == NULL)
        {
            node->next = *head;
            *head = node;
        }
        else
        {
            node->next = cur;
            pre->next = node;
        }
    }
}

Poly *readPoly()
{
    int terms;
    if (scanf("%d", &terms) != 1)
        return NULL;

    float *coefArr = (float *)malloc(sizeof(float) * terms);
    int *expArr = (int *)malloc(sizeof(int) * terms);

    for (int i = 0; i < terms; i++)
        scanf("%f", &coefArr[i]);
    for (int i = 0; i < terms; i++)
        scanf("%d", &expArr[i]);

    Poly *head = NULL;
    for (int i = 0; i < terms; i++)
        insertTerm(&head, coefArr[i], expArr[i]);

    free(coefArr);
    free(expArr);
    return head;
}

Poly *multiply(Poly *A, Poly *B)
{
    Poly *C = NULL;
    for (Poly *p = A; p; p = p->next)
        for (Poly *q = B; q; q = q->next)
            insertTerm(&C, p->coef * q->coef, p->exp + q->exp);
    return C;
}

void printPoly(Poly *p)
{
    int count = 0;
    for (Poly *cur = p; cur; cur = cur->next)
        count++;

    printf("%d\n", count);

    Poly *cur = p;
    for (int i = 0; i < count; i++)
    {
        printf("%.0f", cur->coef);
        if (i < count - 1)
            printf(" ");
        cur = cur->next;
    }
    printf("\n");

    cur = p;
    for (int i = 0; i < count; i++)
    {
        printf("%d", cur->exp);
        if (i < count - 1)
            printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        Poly *A = readPoly();
        if (A == NULL)
            break; // EOF

        Poly *B = readPoly();
        if (B == NULL)
            break;

        Poly *C = multiply(A, B);
        printPoly(C);
    }
    return 0;
}
