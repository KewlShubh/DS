#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int a[20];
    int top;
    int bottom;
} stack;

void init(stack *p)
{
    p->bottom = 20;
    p->top = -1;
}

void push(stack *p, int ele, int choice)
{
    if (!isfull(p))
    {
        if (choice == 1)
        {
            p->top++;
            p->a[p->top] = ele;
        }
        else
        {
            p->bottom--;
            p->a[p->bottom] = ele;
        }
    }
}

void pop(stack *p, int choice)
{
    if (!isempty(p))
    {
        if (choice == 1)
        {
            p->top--;
        }
        else
        {
            p->bottom++;
        }
    }
}