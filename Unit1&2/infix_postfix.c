#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
    char a[50];
    int top;
} stack;

void push(stack *p, char ele)
{
    p->top++;
    p->a[p->top] = ele;
}

char pop(stack *p)
{
    return p->a[p->top--];
}

int precedence(char a)
{
    switch (a)
    {
    case '#':
        return -1;
    case '(':
        return 5;
    case '+':
    case '-':
        return 10;
    case '*':
    case '/':
        return 20;
    case '^':
        return 30;
    }
}

char peek(stack *p)
{
    return p->a[p->top];
}

void eval(char *a, char *b)
{
    stack p;
    p.top = -1;
    char token;
    token = a[0];
    int k = 0;
    int i = 0;
    while (i < strlen(a))
    {
        token = a[i];
        i++;
        if (token == '(')
        {
            push(&p, token);
        }
        else if (isalnum(token))
        {
            b[k++] = token;
        }
        else if (token == ')')
        {
            while (peek(&p) != '(')
            {
                b[k++] = pop(&p);
            }
            pop(&p);
        }
        else
        {
            while (precedence(p.a[p.top]) >= precedence(token))
            {
                b[k++] = pop(&p);
            }
            push(&p, token);
        }
    }
    while (p.top != -1)
    {
        b[k++] = pop(&p);
    }
    b[k] = '\0';
}

int perform(char action, int x, int y)
{
    switch (action)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    }
}

void eval_post(char *a)
{
    stack p;
    p.top = -1;
    int i = 0;
    int x, y, val;
    char token;
    while (i < strlen(a))
    {
        token = a[i];
        i++;

        if (isdigit(token))
        {
            push(&p, token - 48);
        }
        else
        {
            y = pop(&p);
            x = pop(&p);
            val = perform(token, x, y);
            push(&p, val);
        }
    }
    printf("Value is: %d", pop(&p));
}

int main()
{
    char a[50];
    char b[50];
    printf("Enter the expression: ");
    gets(a);
    eval(a, b);
    printf("Postfix evaluation is: ");
    printf("%s\n", b);
    eval_post(b);
    return 0;
}