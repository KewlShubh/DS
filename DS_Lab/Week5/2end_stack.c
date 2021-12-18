#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *s;
    int front;
    int end;
    int cap;
} stack;

void init(stack *p)
{
    printf("Enter the capacity: ");
    scanf("%d", &p->cap);
    p->s = (int *)malloc((p->cap) * sizeof(int));
    p->front = -1;
    p->end = p->cap;
}

int isfull(stack *s)
{
    return s->front == s->end - 1;
}

void push(stack *p, int ele, int choice)
{
    if (isfull(p))
    {
        printf("Overflow\n");
    }
    else
    {

        switch (choice)
        {
        case 1:
            p->front++;
            p->s[p->front] = ele;
            break;
        case 2:
            p->end--;
            p->s[p->end] = ele;
            break;
        }
    }
}

int pop(stack *p, int choice)
{
    switch (choice)
    {
    case 1:
        if (p->front == -1)
        {
            printf("Stack 1 is empty\n");
            return -9999;
        }
        else
        {
            return p->s[p->front--];
        }
        break;
    case 2:
        if (p->end == p->cap)
        {
            printf("Stack2 is empty\n");
            return -9999;
        }
        else
        {
            return p->s[p->end++];
        }
        break;
    }
}

void display(stack *p, int choice)
{
    int i;
    switch (choice)
    {
    case 1:
        for (i = 0; i <= p->front; i++)
        {
            printf("%d\t", p->s[i]);
        }
        break;
    case 2:
        for (i = p->cap - 1; i >= p->end; i--)
        {
            printf("%d\t", p->s[i]);
        }
        break;
    }
    printf("\n");
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    init(s);
    int choice;
    int ele;
    //printf("Enter\n1.Push to stack 1\n2.Push to stack 2\n3.Pop from stack 1\n4.Pop from stack 2\n5.Display stack 1\n6.Display stack 2\n7.Exit\n");
    while (1 != 0)
    {
        printf("Enter\n1.Push to stack 1\n2.Push to stack 2\n3.Pop from stack 1\n4.Pop from stack 2\n5.Display stack 1\n6.Display stack 2\n7.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element for stack 1: ");
            scanf("%d", &ele);
            push(s, ele, 1);
            break;
        case 2:
            printf("Enter the element for stack 2: ");
            scanf("%d", &ele);
            push(s, ele, 2);
            break;
        case 3:
            pop(s, 1);
            break;
        case 4:
            pop(s, 2);
            break;
        case 5:
            display(s, 1);
            break;
        case 6:
            display(s, 2);
            break;
        case 7:
            exit(0);
        }
    }
}