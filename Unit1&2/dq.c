#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct dq
{
    int a[max];
    int front;
    int rear;
} dq;

void init(dq *q)
{
    q->front = -1;
    q->rear = -1;
}

int isempty(dq *p)
{
    return p->rear == -1;
}

int isfull(dq *p)
{
    return (p->rear + 1) % max == p->front;
}

void insertbeg(dq *q, int ele)
{
    if (isfull(q))
    {
        printf("Queue is full \n");
    }
    else
    {
        if (q->rear == -1)
        {
            q->front = q->rear = 0;
            q->a[0] = ele;
        }
        else
        {
            q->front = (q->front - 1 + max) % max;
            q->a[q->front] = ele;
        }
    }
}

void insertend(dq *q, int ele)
{
    if (isfull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = q->rear = 0;
            q->a[0] = ele;
        }
        else
        {
            q->rear = (q->rear + 1) % max;
            q->a[q->rear] = ele;
        }
    }
}

void deletebeg(dq *q)
{
    if (isempty(q))
    {
        printf("Empty queue\n");
    }
    else
    {
        if (q->rear == 0 && q->front == 0)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % max;
        }
    }
}

void deleteend(dq *q)
{
    if (isempty(q))
    {
        printf("Empty queue\n");
    }
    else
    {
        if (q->rear == 0 && q->front == 0)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->rear = (q->rear - 1 + max) % max;
        }
    }
}

void display(dq *q)
{
    if (isempty(q))
    {
        printf("Empty queue. Nothing to display\n");
    }
    else
    {
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d\t", q->a[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", q->a[i]);
    }
}

int main()
{
    dq *p = (dq *)malloc(sizeof(dq));
    init(p);
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
            insertbeg(p, ele);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &ele);
            insertend(p, ele);
            break;
        case 3:
            printf("Deleted from the front of the queue\n");
            deletebeg(p);
            break;
        case 4:
            printf("Deleted from the end of the queue");
            deleteend(p);
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