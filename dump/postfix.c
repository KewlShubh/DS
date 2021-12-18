#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    char *s;
    int size;
    int top;
    int capacity;
} stack;
void create(stack *pst, int capacity)
{
    pst->s = malloc(capacity * sizeof(char));
    pst->top = -1;
    pst->capacity = capacity;
    pst->size = 1;
}
void double_stack(stack *pst)
{
    pst->capacity = (pst->capacity) * 2;
    pst->s = realloc(pst->s, pst->capacity);
}
void push(stack *pst, char ele)
{
    if ((pst->top) + 1 == (pst->capacity))
    {
        double_stack(pst);
    }
    (pst->top)++;
    (pst->s)[pst->top] = ele;
    (pst->size)++;
}
void pop(stack *pst)
{
    char ele;
    if (pst->top == -1)
    {
        printf("The stack is empty:\n");
    }
    else
    {
        ele = (pst->s)[pst->top];
        //(pst->s)[pst->top] = NULL;
        (pst->top)--;
        (pst->size)--;
    }
    if (ele != '(')
        printf("%c", ele);
}
void check(stack *pst, char a)
{
    if (a == '/' || a == '*' || a == '+' || a == '-' || a == '^' || a == '(' || a == ')')
    {
        postfix(pst, a);
    }
    else
    {
        printf("%c", a);
    }
}
int precedence(char a)
{
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
}
void postfix(stack *pst, char a)
{
    int i = 0, x, y;
    if (a == '(')
        push(pst, a);
    else if (a == ')')
    {
        while (pst->s[i] != '(')
        {
            pop(pst);
            i++;
        }
    }
    else
    {
        if (pst->top == -1)
        {
            push(pst, a);
        }
        else
        {
            x = precedence(pst->s[pst->top]);
            y = precedence(a);
            if (x > y)
            {
                pop(pst);
                postfix(pst, a);
            }
            else if (x < y)
            {
                push(pst, a);
            }
            else
            {
                if (x == 1)
                {
                    pop(pst);
                    postfix(pst, a);
                }
                else
                {
                    push(pst, a);
                }
            }
        }
    }
}
void display(stack c)
{
    for (int i = c.top; i >= 0; i--)
    {
        printf("%c", c.s[i]);
    }
    printf("\n");
}
int main()
{
    int i = 0;
    char a[100];
    int capa = 100;
    stack s;
    create(&s, capa);
    printf("Please enter the expression:\n");
    gets(a);
    while (a[i] != '\0')
    {
        check(&s, a[i]);
        i++;
    }
    if (s.top != 0)
    {
        display(s);
    }
    return 0;
}