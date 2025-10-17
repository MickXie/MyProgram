#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    char a[MAX];
    int top;
} SChar;
typedef struct
{
    long long a[MAX];
    int top;
} SInt;

static inline int prec(char op) { return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2
                                                                                                 : 0; }
static inline int emptyC(SChar *s) { return s->top < 0; }
static inline char peekC(SChar *s) { return s->a[s->top]; }
static inline void pushC(SChar *s, char c) { s->a[++s->top] = c; }
static inline char popC(SChar *s) { return s->a[s->top--]; }

static inline void pushI(SInt *s, long long v) { s->a[++s->top] = v; }
static inline long long popI(SInt *s) { return s->a[s->top--]; }

// 將花式減號、全形空白等正規化
void normalize(char *s)
{
    for (int i = 0; s[i]; ++i)
    {
        unsigned char c = (unsigned char)s[i];
        // 常見減號：U+2013, U+2014, U+2212
        if ((c == 0xE2 && (unsigned char)s[i + 1] == 0x80 && ((unsigned char)s[i + 2] == 0x93 || (unsigned char)s[i + 2] == 0x94)) ||
            (c == 0xE2 && (unsigned char)s[i + 1] == 0x88 && (unsigned char)s[i + 2] == 0x92))
        {
            s[i] = '-';
            s[i + 1] = ' ';
            s[i + 2] = ' '; // 粗暴覆蓋為 ASCII，避免殘留多位元組
        }
        // 非斷行空白等 → 一般空白
        if (c == 0xC2 && (unsigned char)s[i + 1] == 0xA0)
        {
            s[i] = ' ';
            s[i + 1] = ' ';
        }
    }
}

// 轉後序：輸出以單一空白分隔 token
void infixToPostfix(const char *in, char *out)
{
    SChar ops;
    ops.top = -1;
    int k = 0;
    for (int i = 0; in[i];)
    {
        if (isspace((unsigned char)in[i]))
        {
            i++;
            continue;
        }
        if (isdigit((unsigned char)in[i]))
        { // 讀完整數字
            while (isdigit((unsigned char)in[i]))
                out[k++] = in[i++];
            out[k++] = ' ';
        }
        else
        {
            char t = in[i++];
            if (t == '(')
                pushC(&ops, t);
            else if (t == ')')
            {
                while (!emptyC(&ops) && peekC(&ops) != '(')
                {
                    out[k++] = popC(&ops);
                    out[k++] = ' ';
                }
                if (!emptyC(&ops) && peekC(&ops) == '(')
                    popC(&ops);
            }
            else if (t == '+' || t == '-' || t == '*' || t == '/')
            {
                while (!emptyC(&ops) && prec(peekC(&ops)) >= prec(t))
                {
                    out[k++] = popC(&ops);
                    out[k++] = ' ';
                }
                pushC(&ops, t);
            }
        }
    }
    while (!emptyC(&ops))
    {
        out[k++] = popC(&ops);
        out[k++] = ' ';
    }
    if (k > 0 && out[k - 1] == ' ')
        k--;
    out[k] = '\0';
}

long long evalPostfix(const char *post)
{
    SInt st;
    st.top = -1;
    for (int i = 0; post[i];)
    {
        if (isspace((unsigned char)post[i]))
        {
            i++;
            continue;
        }
        if (isdigit((unsigned char)post[i]))
        {
            long long v = 0;
            while (isdigit((unsigned char)post[i]))
                v = v * 10 + (post[i++] - '0');
            pushI(&st, v);
        }
        else
        {
            char op = post[i++];
            long long b = popI(&st), a = popI(&st), r = 0;
            if (op == '+')
                r = a + b;
            else if (op == '-')
                r = a - b;
            else if (op == '*')
                r = a * b;
            else if (op == '/')
                r = a / b;
            pushI(&st, r);
        }
    }
    return popI(&st);
}

int main(void)
{
    char infix[MAX];
    if (!fgets(infix, sizeof(infix), stdin))
        return 0;
    infix[strcspn(infix, "\n")] = 0;
    normalize(infix);

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    printf("%lld\n", evalPostfix(postfix));
    return 0;
}
