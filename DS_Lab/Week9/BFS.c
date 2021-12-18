// Graph traversal using BFS
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int **createMat(int n)
{
    int adjmat[MAX][MAX];
}

void init_v(int visited[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }
}

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
    p->cap = MAX;
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

void bfs(int src, int adjmat[MAX][MAX], int visited[MAX], int n)
{
    printf("Entered here1\n");
    int d_vertex;
    queue *p = (queue *)malloc(sizeof(queue));
    init(p);
    printf("Entered here2\n");
    printf("%d\t", src);
    visited[src] = 1;
    enq(p, src);
    printf("Entered here3\n");
    while (!isempty(p))
    {
        d_vertex = deq(p);
        printf("Entered here4\n");
        for (int j = 0; j < n; j++)
        {
            if (adjmat[d_vertex][j] == 1 && visited[j] == 0)
            {
                printf("%d\t", j);
                visited[j] = 1;
                enq(p, j);
            }
        }
    }
    printf("\n");
}

int main()
{
    int visited[MAX];
    int choice;
    int adjmat[MAX][MAX] = {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}};
    /*for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("Enter choice: ");
            scanf("%d", &choice);
            adjmat[i][j] = choice;
        }
    }*/
    init_v(visited);
    printf("Enter the source: ");
    scanf("%d", &choice);
    bfs(choice, adjmat, visited, MAX);
    return 0;
}