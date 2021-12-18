#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct queue
{
    int *s;
    int front;
    int rear;
    int capacity;
} queue;
void create(queue *pst, int cap)
{
    //int arr[4];
    pst->capacity = cap;
    pst->front = -1;
    pst->rear = -1;
    pst->s = malloc(sizeof(int) * cap);
}
int isfull(queue *pst)
{
    if (pst->front - pst->rear == 1 || (pst->front == 0 && pst->rear == pst->capacity - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(queue *pst)
{
    if (pst->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *pst, int ele)
{
    // printf("enter");
    if (isempty(pst))
    {
        pst->front = 0;
        pst->rear = 0;
        pst->s[pst->rear] = ele;
    }
    else if (isfull(pst))
    {
        printf("The list is Full.\n");
    }
    else
    {
        pst->rear = (pst->rear + 1) % pst->capacity;
        pst->s[pst->rear] = ele;
    }
}
void dequeue(queue *pst)
{

    if (isempty(pst))
    {
        printf("The list is empty. \n");
    }
    else if (pst->front == pst->rear)
    {
        pst->front = -1;
        pst->rear = -1;
    }
    
    else
    {
        //pst->s[pst->front] = NULL;
        pst->front = (pst->front + 1) % pst->capacity;
    }
}
void display(queue s)
{
    if (s.front > s.rear)
    {
        for (int i = s.front; i != s.rear; i = (i + 1) % s.capacity)
        {
            //printf("%d", i);
            printf("%d\t", s.s[i]);
        }
        printf("%d\t", s.s[s.rear]);
    }
    else
    {
        for(int i = s.front  ; i <= s.rear ; i++)
        {
            printf("%d\t", s.s[i]);
        }
    }
}
int main()
{
    queue s;
    int cap = 4;
    int num, ele;
    create(&s, cap);
    while (1 != 0)
    {
        system("cls");
        printf("1.INSERT\n2.DELET\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Please enter thr number u want to enter:\n");
            scanf("%d", &ele);
            enqueue(&s, ele);
            getch();
            break;
        case 2:
            dequeue(&s);
            printf("%d\n", s.front);
            getch();
            break;
        case 3:
            display(s);
            getch();
            break;
        case 4:
            exit(0);
        }
    }
}