#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int q[10];
    int front;
    int rear;
    int cap;
} queue;

void init(queue *p)
{
    p->cap = 10;
    p->front = -1;
    p->rear = -1;
}

int isempty(queue *p)
{
    return p->rear == -1;
}

int isfull(queue *p)
{
    return (p->rear + 1) % p->cap == p->front;
}

void enf(queue *p, int ele)
{
    if (isfull(p))
    {
        printf("Queue is full \n");
    }
    else
    {
        if (p->rear == -1)
        {
            p->front = p->rear = 0;
            p->q[0] = ele;
            printf("Inserted successfully\n");
        }
        else
        {
            printf("Second\n");
            p->front = (p->front - 1 + p->cap) % p->cap;
            p->q[p->front] = ele;
        }
    }
}

void enr(queue *p, int ele)
{
    if (isfull(p))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (p->front == -1)
        {
            p->front = p->rear = 0;
            p->q[0] = ele;
        }
        else
        {
            p->rear = (p->rear + 1) % p->cap;
            p->q[p->rear] = ele;
        }
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
    enf(p, 10);
    enf(p, 20);
    enr(p, 30);
    enr(p, 40);
    display(p);
}