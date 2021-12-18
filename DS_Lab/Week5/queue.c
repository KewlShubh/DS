#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *q;
    int front;
    int rear;
    int cap;
} queue;

int isempty(queue *p)
{
    return p->rear == p->front == -1;
}

int isfull(queue *p)
{
    return p->rear - p->front == p->cap - 1;
}

void init(queue *p)
{
    printf("Enter the capacity: ");
    scanf("%d", &p->cap);
    p->q = (int *)malloc((p->cap) * sizeof(int));
    p->front = p->rear = -1;
}

void enq(queue *p, int ele)
{
    if (isfull(p))
    {
        printf("Queue is full\n");
    }
    else
    {
        p->rear++;
        p->q[p->rear] = ele;
    }

    if (p->front == -1)
    {
        p->front++;
    }
}

int deq(queue *p)
{
    if (isempty(p))
    {
        printf("Empty queue\n");
        return -9999;
    }
    else if (!isfull(p) && (p->front == p->rear))
    {
        int x = p->q[p->rear];
        p->rear = p->front = -1;
        return x;
    }
    else
    {
        return p->q[p->front++];
    }
}

void display(queue *p)
{
    if (p->front == -1)
    {
        printf("Empty list\n");
    }
    else
    {
        for (int i = p->front; i <= p->rear; i++)
        {
            printf("%d\t", p->q[i]);
        }
        printf("\n");
    }
}

int main()
{
    queue *p = (queue *)malloc(sizeof(queue));
    init(p);
    enq(p, 10);
    enq(p, 20);
    enq(p, 30);
    //enq(p, 40);
    //enq(p, 50);
    display(p);
    deq(p);
    deq(p);
    deq(p);
    display(p);
    enq(p, 40);
    enq(p, 50);
    display(p);
    return 0;
}