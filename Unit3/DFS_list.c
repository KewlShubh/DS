#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

typedef struct graphdetails
{
    int vertices;
    int edges;
    node **gnode;
} graphdetails;

typedef struct queue
{
    int *q;
    int front;
    int rear;
    int cap;
} queue;

void q_init(queue *p)
{
    p->front = p->rear = -1;
    p->cap = 5;
    // printf("Enter the capacity: ");
    // scanf("%d", &p->cap);
    p->q = (int *)malloc(p->cap * sizeof(int));
}

void enq(queue *p, int ele)
{
    p->q[++(p->rear)] = ele;
    if (p->front == -1)
    {
        p->front++;
    }
}

int deq(queue *p)
{
    return p->q[p->front++];
}

int isempty(queue *p)
{
    return p->front - p->rear == 1;
}

void createGraph(graphdetails *graph)
{
    graph->gnode = (node **)malloc(sizeof(node *) * graph->vertices);
    for (int i = 0; i < graph->vertices; i++)
    {
        graph->gnode[i] = NULL;
    }
}

node *init(int n)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = n;
    temp->next = NULL;
    return temp;
}

void readGraph(graphdetails *graph)
{
    int i, j, n = graph->vertices, ans = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Is %d linked to %d:", j, i);
            scanf("%d", &ans);
            if (ans == 1)
            {
                node *temp = init(j);
                if (graph->gnode[i] == NULL)
                {
                    graph->gnode[i] = temp;
                }
                else
                {
                    temp->next = graph->gnode[i];
                    graph->gnode[i] = temp;
                }
            }
        }
    }
}

void bfst(graphdetails *graph, int source, int *visited)
{
    int del_vertex;
    node *start = NULL;
    queue *pq = (queue *)malloc(sizeof(queue));
    q_init(pq);
    visited[source] = 1;
    enq(pq, source);
    printf("%d\t", source);

    while (!isempty(pq))
    {
        del_vertex = deq(pq);
        start = graph->gnode[del_vertex];
        while (start != NULL)
        {
            if (visited[start->info] != 1)
            {
                visited[start->info] = 1;
                enq(pq, start->info);
                printf("%d\t", start->info);
            }
            start = start->next;
        }
    }
}

void dfst()
{
}

int main()
{
    graphdetails *graph = (graphdetails *)malloc(sizeof(graphdetails));
    graph->gnode = NULL;
    graph->edges = 0;
    graph->vertices = 5;
    int visited[4] = {0, 0, 0, 0, 0};
    createGraph(graph);
    readGraph(graph);
    bfst(graph, 0, visited);
    return 0;
}