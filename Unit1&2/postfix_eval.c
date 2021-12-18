#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
    int a[50];
    int top;
} stack;

void push(stack *p, int ele)
{
    p->top++;
    p->a[p->top] = ele;
}

int pop(stack *p)
{
    return p->a[p->top--];
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

void eval(char *a)
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
    printf("Enter the postix expression: ");
    gets(a);
    eval(a);
    return 0;
}