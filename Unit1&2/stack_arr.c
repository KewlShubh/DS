#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *s;
    int top;
    int size;
    int capacity;
} stack;

void reallot(stack *p)
{
    p->s = (int *)realloc(p->s, 2 * p->capacity);
}

void push(stack *p, int ele)
{
    if (p->size == p->capacity)
    {
        reallot(p);
    }
    p->top++;
    p->size++;
    p->s[p->top] = ele;
}

void pop(stack *p)
{
    if (p->size == 0)
    {
        printf("No elements left in the stack\n");
    }
    else
    {
        p->top--;
        p->size--;
    }
}

void display(stack *p)
{
    for (int i = 0; i < p->size; i++)
    {
        printf("%d\t", p->s[i]);
    }
    printf("\n");
}

int main()
{
    stack p;
    printf("Enter the capacity: ");
    scanf("%d", &(p.capacity));
    p.size = 0;
    p.top = -1;
    p.s = (int *)malloc(p.capacity * sizeof(int));
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    display(&p);
    pop(&p);
    display(&p);
    pop(&p);
    display(&p);
    pop(&p);
    display(&p);
    pop(&p);
    display(&p);
    pop(&p);
}