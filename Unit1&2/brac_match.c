#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char a[50];
    int top;
} stack;

void init(stack *p)
{
    p->top = -1;
}

void push(stack *p, char ele)
{
    p->top++;
    p->a[p->top] = ele;
}

char pop(stack *p)
{
    p->top--;
}

char peek(stack *p)
{
    return p->a[p->top];
}

int match(char *a)
{
    stack *p = (stack *)malloc(sizeof(stack));
    init(p);
    int i = 0;
    char token;
    while (i < strlen(a))
    {
        token = a[i];
        i++;
        if (token == '(')
            push(p, token);
        else if (token == ')')
        {
            if (peek(p) != '(')
                return -1;
            else
                pop(p);
        }
        if (token == '{')
            push(p, token);
        else if (token == '}')
        {
            if (peek(p) != '{')
                return -1;
            else
                pop(p);
        }
        if (token == '[')
            push(p, token);
        else if (token == ']')
        {
            if (peek(p) != '[')
                return -1;
            else
                pop(p);
        }
    }
    if (p->top != -1)
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    char a[50];
    gets(a);
    printf("%d", match(a));
}