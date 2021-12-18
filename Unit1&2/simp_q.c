#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
    int *q;
    int front;
    int rear;
    int cap;
} queue;

void init(queue *p)
{
    p->front = p->rear = -1;
    printf("Enter the capacity: ");
    scanf("%d", &p->cap);
    p->q = (int *)malloc(p->cap * sizeof(int));
}

int isfull(queue *p)
{
    return p->rear == p->cap - 1;
}

int isempty(queue *p)
{
    return p->front - p->rear == 1;
}

void enq(queue *p, int ele)
{
    if (isfull(p))
    {
        printf("Queue is full :'(\n");
    }
    else
    {
        p->q[++(p->rear)] = ele;
    }
    if (p->front == -1)
    {
        p->front++;
    }
}

void deq(queue *p)
{
    if (isempty(p))
    {
        printf("Queue is empty :'(\n");
    }
    else
    {
        p->front++;
    }

    if (isfull(p) && p->front == p->rear + 1)
    {
        printf("Resetting queue\n");
        p->front = p->rear = -1;
    }
}

void display(queue *p)
{
    int i = 0;
    for (i = p->front; i != p->rear; i++)
    {
        printf("%d\t", p->q[i]);
    }
    printf("%d\n", p->q[i]);
}

int main()
{
    queue *p = (queue *)malloc(sizeof(queue));
    init(p);
    enq(p, 10);
    enq(p, 20);
    enq(p, 30);
    display(p);
    deq(p);
    deq(p);
    deq(p);
    enq(p, 40);
    display(p);
}