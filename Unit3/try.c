#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct graph
{
    int v;
    int e;
    node **a;
} graph;

void init_graph(graph *g)
{
    g->a = (node **)malloc(sizeof(node) * (g->v));
    for (int i = 0; i < g->v; i++)
    {
        g->a[i] = 0;
    }
}

node *init_list(node *temp, int d)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

void create(graph *g)
{
    int c = 0;
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            printf("Enter 1 if %d and %d are connected: ", i, j);
            scanf("%d", &c);
            if (c == 1)
            {
                node *temp = init_list(temp, j);
                if (g->a[i] == NULL)
                {
                    g->a[i] = temp;
                }
                else
                {
                    temp->next = g->a[i];
                    g->a[i] = temp;
                }
            }
        }
    }
}

void insert_arc(graph *g, int v1, int v2)
{
    node *temp = init_list(temp, v2);
    if (g->a[v1] == NULL)
    {
        g->a[v1] = temp;
    }
    else
    {
        temp->next = g->a[v1];
        g->a[v1] = temp;
    }
}

void delete_arc(graph *g, int v1, int v2)
{
    node *temp1 = g->a[v1], *temp2 = g->a[v2];
    node *prev = NULL;
    while (temp1 != NULL)
    {
        if (temp1->data == v2)
        {
            if (prev == NULL)
            {
                g->a[v1] = temp1->next;
            }
            else
            {
                prev->next = temp1->next;
            }
            free(temp1);
        }
        else
        {
            prev = temp1;
            temp1 = temp1->next;
        }
    }
    prev = NULL;
    while (temp2 != NULL)
    {
        if (temp2->data == v1)
        {
            if (prev == NULL)
            {
                g->a[v2] = temp2->next;
            }
            else
            {
                prev->next = temp2->next;
            }
            free(temp2);
        }
        else
        {
            prev = temp2;
            temp2 = temp2->next;
        }
    }
}

void is_adjacent(graph *g, int v1, int v2)
{
    int flag = 0;
    node *temp = g->a[v1];
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data == v2)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Adjacent nodes\n");
    }
    else
    {
        printf("Non-adjacent nodes\n");
    }
}

void display(graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        node *temp = g->a[i];
        printf("%d:\n", i);
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->a = NULL;
    g->v = 4;
    g->e = 0;
    init_graph(g);
    create(g);
    display(g);
    printf("Inserting arc\n");
    insert_arc(g, 0, 2);
    display(g);
    printf("Insertion done\n");
    /**printf("Deleting arc\n");
    delete_arc(g, 0, 2);
    display(g);
    printf("deletion done\n");**/
    is_adjacent(g, 0, 1);
    return 0;
}