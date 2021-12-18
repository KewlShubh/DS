#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *q;
    int front;
    int rear;
    int cap;
} queue;

void init(queue *p, int cap)
{
    p->cap = cap;
    p->q = (int *)malloc(sizeof(int) * cap);
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
        }
        else
        {
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

int df(queue *p)
{
    int x;
    if (isempty(p))
    {
        printf("Empty queue\n");
    }
    else
    {
        if (p->front == 0)
        {
            x = p->q[p->front];
            p->front = p->rear = -1;
        }
        else
        {
            x = p->q[p->front];
            p->front = (p->front + 1) % p->cap;
        }
    }
}

int dr(queue *p)
{
    int x;
    if (isempty(p))
    {
        printf("Empty queue\n");
    }
    else
    {
        if (p->rear == 0)
        {
            x = p->q[p->rear];
            p->front = p->rear = -1;
        }
        else
        {
            x = p->q[p->rear];
            p->rear = (p->rear - 1) % p->cap;
        }
    }
}

void display(queue *p)
{
    if (isempty(p))
    {
        printf("Empty queue. Nothing to display\n");
    }
    else
    {
        int i = p->front;
        while (i != p->rear)
        {
            printf("%d\t", p->q[i]);
            i = (i + 1) % p->cap;
        }
        printf("%d\n", p->q[i]);
    }
}

int main()
{
    queue *p = (queue *)malloc(sizeof(queue));
    int cap;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &cap);
    init(p, cap);

    int choice, ele;
    while (1 != 0)
    {
        printf("Enter\n1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            enf(p, ele);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &ele);
            enr(p, ele);
            break;
        case 3:
            printf("Deleted %d from the queue", df(p));
            break;
        case 4:
            printf("Deleted %d from the queue", dr(p));
            break;
        case 5:
            display(p);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}