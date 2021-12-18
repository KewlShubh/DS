#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
    char data;
    struct stack *link;
} stack;

void init(stack **p)
{
    *p = (stack *)malloc(sizeof(stack));
    (*p)->link = NULL;
}

void push(stack **p, char ele)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->link = NULL;
    if (*p == NULL)
        *p = temp;
    else
    {
        temp->link = *p;
        *p = temp;
    }
    printf("Pushed value is :%c\n", (*p)->data);
}

char peek(stack **p)
{
    return (*p)->data;
}

char pop(stack **p)
{
    stack *temp = *p;
    *p = (*p)->link;
    char x = temp->data;
    free(temp);
    return x;
}

int process(stack **p, char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        switch (a[i])
        {
        case '[':
        case '(':
        case '{':
            push(p, a[i]);
            break;
        case ']':
            if (peek(p) != '[')
            {
                printf("Peek value: %c\n", peek(p));
                return 0;
            }
        case '}':
            if (peek(p) != '{')
                return 0;
        case ')':
            if (peek(p) != '(')
                return 0;
        }
    }
    return 1;
}

int main()
{
    stack *p;
    init(&p);
    char a[50];
    printf("Enter the string: ");
    gets(a);
    printf("%d\n", process(&p, a));
}