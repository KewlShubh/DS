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
    return (p->rear + 1) % p->cap == p->front;
}

int isempty(queue *p)
{
    return p->front == p->rear == -1;
}

void enq(queue *p, int ele)
{
    if (isfull(p))
    {
        printf("Queue is full :'(\n");
    }
    else
    {
        p->rear++;
        p->rear = p->rear % p->cap;
        //printf("The value of rear is %d: \n", p->rear);
        p->q[p->rear] = ele;
        //printf("The value to be entered is: %d\n", p->q[p->rear % p->cap]);
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
    else if (p->front == p->rear)
    {
        p->front = p->rear = -1;
    }
    else
    {
        p->front = (p->front + 1) % p->cap;
        //printf("front value:%d\n", p->front);
    }
}

void display(queue *p)
{
    int i = p->front;
    while (i != p->rear)
    {
        printf("%d\t", p->q[i]);
        i = (i + 1) % p->cap;
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
    //deq(p);
    enq(p, 50);
    enq(p, 60);
    display(p);
}