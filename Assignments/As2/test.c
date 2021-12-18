#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct node
{
    int vid;
    int rowNo;
    int colNo;
    struct node *next;
} node;

typedef struct graphdetails
{
    int vertices;
    node **gnode;
} graphdetails;

typedef struct queue
{
    int *q;
    int front;
    int rear;
    int cap;
} queue;

// Queue functions

void q_init(queue *p)
{
    p->front = p->rear = -1;
    p->cap = MAX;
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

int leq(queue *p)
{
    return p->q[(p->rear)--];
}

int deq(queue *p)
{
    return p->q[p->front++];
}

int isempty(queue *p)
{
    return p->front - p->rear == 1;
}
// Queue function ends

int findRows()
{
    FILE *fs = fopen("input.txt", "r");
    char str[100];
    int i = 0;
    while (fgets(str, 100, fs) != NULL)
    {
        i++;
    }
    fclose(fs);
    return i - 2;
}

node *source(graphdetails *graph, int x, int y)
{
    node *temp = graph->gnode[x];
    while (temp != NULL && temp->colNo != y)
    {
        temp = temp->next;
    }
    return temp;
}

void createGraph(graphdetails *graph)
{
    graph->gnode = (node **)malloc(sizeof(node *) * graph->vertices);
    for (int i = 0; i < graph->vertices; i++)
    {
        graph->gnode[i] = NULL;
    }
}

void insGraph(graphdetails *graph, int i, int j, int vid)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->vid = vid;
    temp->rowNo = i;
    temp->colNo = j;
    temp->next = NULL;
    if (graph->gnode[i] != NULL)
        temp->next = graph->gnode[i];
    graph->gnode[i] = temp;
}

void readGraph(graphdetails *graph, int *start_x, int *start_y, int *end_x, int *end_y)
{
    createGraph(graph);
    char st[10];
    char en[10];
    char str[100];
    int matrix[100][100];
    int i = 0, vid = 1;
    FILE *fs = fopen("input.txt", "r");
    fgets(st, 6, fs);
    fgets(en, 6, fs);
    *start_x = st[0] - 48;
    *start_y = st[2] - 48;
    *end_x = en[0] - 48;
    *end_y = en[2] - 48;
    while (fgets(str, 100, fs) != NULL)
    {
        for (int j = 0; j < strlen(str); j += 2)
        {
            if (str[j] == '0')
            {
                insGraph(graph, i, j / 2, vid);
                vid++;
            }
        }
        i++;
    }
    fclose(fs);
}

void printGraph(graphdetails *graph)
{
    node *temp;
    for (int i = 0; i < graph->vertices; i++)
    {
        temp = graph->gnode[i];
        while (temp != NULL)
        {
            printf("%d\t", temp->vid);
            temp = temp->next;
        }
        printf("\n");
    }
}

node *find(graphdetails *graph, node *curr, int k)
{
    node *temp = NULL;
    if (k == 1 && curr->rowNo < graph->vertices)
    {
        temp = graph->gnode[curr->rowNo + 1];
        while (temp != NULL)
        {
            if (temp->colNo == curr->colNo)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    else
    {
        temp = graph->gnode[curr->rowNo];
        while (temp != NULL)
        {
            if (temp->colNo == curr->colNo + 1)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

void dfst(graphdetails *graph, queue *q, node *curr, int end_x, int end_y, int *flag)
{
    enq(q, curr->vid);
    if (curr->colNo == end_y && curr->rowNo == end_x)
    {
        *flag = 1;
    }
    else
    {
        node *nex;
        if (*flag != 1)
        {
            nex = find(graph, curr, 1);
            if (nex != NULL)
                dfst(graph, q, nex, end_x, end_y, flag);
        }
        if (*flag != 1)
        {
            nex = find(graph, curr, 0);
            if (nex != NULL)
                dfst(graph, q, nex, end_x, end_y, flag);
        }
    }
    if (*flag != 1)
    {
        leq(q);
    }
}

void bfst(graphdetails *graph, queue *q, node *curr, int end_x, int end_y, int *flag)
{
    enq(q, curr->vid);
    if (curr->colNo == end_y && curr->rowNo == end_x)
    {
        *flag = 1;
    }
    else
    {
        node *nex;
        if (*flag != 1)
        {
            nex = find(graph, curr, 0);
            if (nex != NULL)
                bfst(graph, q, nex, end_x, end_y, flag);
        }
        if (*flag != 1)
        {
            nex = find(graph, curr, 1);
            if (nex != NULL)
                bfst(graph, q, nex, end_x, end_y, flag);
        }
    }
    if (*flag != 1)
    {
        leq(q);
    }
}

void findPath(graphdetails *graph, queue *qDFS, queue *qBFS, node *start, int end_x, int end_y)
{
    int flag = 0;
    q_init(qDFS);
    q_init(qBFS);
    dfst(graph, qDFS, start, end_x, end_y, &flag);
    flag = 0;
    bfst(graph, qBFS, start, end_x, end_y, &flag);
}

void storePath(queue *qDFS, queue *qBFS)
{
    FILE *f = fopen("outdfs.txt", "w");
    int vid;
    if (isempty(qDFS))
    {
        printf("No path found using DFS\nStoring -1 in the outdfs.txt\n");
        fprintf(f, "%d\n", -1);
    }
    else
    {
        printf("Path found using DFS\nStoring path in the outdfs.txt \n");
        while (!isempty(qDFS))
        {
            vid = deq(qDFS);
            fprintf(f, "%d\n", vid);
            printf("%d\n", vid);
        }
    }
    fclose(f);
    f = fopen("outbfs.txt", "w");
    if (isempty(qBFS))
    {
        printf("No path found using BFS\nStoring -1 in the outbfs.txt \n");
        fprintf(f, "%d\n", -1);
    }
    else
    {
        printf("Path found using BFS\nStoring path in the outbfs.txt \n");
        while (!isempty(qBFS))
        {
            vid = deq(qBFS);
            fprintf(f, "%d\n", vid);
            printf("%d\n", vid);
        }
    }
    fclose(f);
}

int main()
{
    int start_x, start_y, end_x, end_y, n = 0;
    node *start;
    graphdetails *graph = (graphdetails *)malloc(sizeof(graphdetails));
    queue *qDFS = (queue *)malloc(sizeof(queue)), *qBFS = (queue *)malloc(sizeof(queue));
    n = findRows();
    graph->vertices = n;
    readGraph(graph, &start_x, &start_y, &end_x, &end_y);
    start = source(graph, start_x, start_y);
    findPath(graph, qDFS, qBFS, start, end_x, end_y);
    storePath(qDFS, qBFS);
    return 0;
}
