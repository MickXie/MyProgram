#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

char infix[MAX];
char postfix[MAX][MAX];
int postCount = 0;

// Stack for operators
char stackOp[MAX];
int topOp = -1;

// Stack for evaluating postfix
int stackVal[MAX];
int topVal = -1;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void pushOp(char op)
{
    stackOp[++topOp] = op;
}

char popOp()
{
    return stackOp[topOp--];
}

void pushVal(int v)
{
    stackVal[++topVal] = v;
}

int popVal()
{
    return stackVal[topVal--];
}

void infixToPostfix()
{
    int i = 0;
    while (infix[i] != '\0')
    {

        if (isdigit(infix[i]))
        {
            char number[MAX];
            int p = 0;

            while (isdigit(infix[i]))
            {
                number[p++] = infix[i++];
            }
            number[p] = '\0';
            strcpy(postfix[postCount++], number);
            continue;
        }

        if (infix[i] == ' ')
        {
            i++;
            continue;
        }

        char curr = infix[i];
        while (topOp != -1 && precedence(stackOp[topOp]) >= precedence(curr))
        {
            char op[2] = {popOp(), '\0'};
            strcpy(postfix[postCount++], op);
        }
        pushOp(curr);
        i++;
    }

    while (topOp != -1)
    {
        char op[2] = {popOp(), '\0'};
        strcpy(postfix[postCount++], op);
    }
}

int evalPostfix()
{
    for (int i = 0; i < postCount; i++)
    {
        if (isdigit(postfix[i][0]))
        {
            pushVal(atoi(postfix[i]));
        }
        else
        {
            int b = popVal();
            int a = popVal();
            char op = postfix[i][0];

            if (op == '+')
                pushVal(a + b);
            else if (op == '-')
                pushVal(a - b);
            else if (op == '*')
                pushVal(a * b);
            else if (op == '/')
                pushVal(a / b);
        }
    }
    return popVal();
}

int main()
{
    fgets(infix, MAX, stdin);

    infixToPostfix();

    for (int i = 0; i < postCount; i++)
    {
        printf("%s ", postfix[i]);
    }
    printf("\n");

    int ans = evalPostfix();
    printf("%d\n", ans);

    return 0;
}
