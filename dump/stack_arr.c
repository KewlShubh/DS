#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *s;
    int size;
    int top;
    int capacity;
} stack;
void create(stack *pst, int capacity)
{
    pst->s = malloc(capacity * sizeof(int));
    pst->top = -1;
    pst->capacity = capacity;
    pst->size = 1;
}
void double_stack(stack *pst)
{
    pst->capacity = (pst->capacity) * 2;
    pst->s = realloc(pst->s, pst->capacity);
}
void push(stack *pst, int ele)
{
    if ((pst->top) + 1 == (pst->capacity))
    {
        double_stack(pst);
    }
    (pst->top)++;
    (pst->s)[pst->top] = ele;
    (pst->size)++;
}
int pop(stack *pst)
{
    int ele;
    if (pst->top == -1)
    {
        printf("The stack is empty:\n");
    }
    else
    {
        ele = (pst->s)[pst->top];
        (pst->s)[pst->top] = NULL;
        (pst->top)--;
        (pst->size)--;
    }
    return ele;
}
void display(stack c)
{
    for (int i = c.top; i >= 0; i--)
    {
        printf("%d\t", c.s[i]);
    }
    printf("\n");
}
int main()
{
    int num;
    int capacity = 100;
    stack c;
    create(&c, capacity);
    printf("Please enter the number: \n");
    scanf("%d", &num);
    push(&c, num);
    push(&c, 20);
    push(&c, 30);
    push(&c, 70);
    display(c);
    pop(&c);
    display(c);
}
