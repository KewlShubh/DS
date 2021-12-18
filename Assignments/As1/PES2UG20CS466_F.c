#include "PES2UG20CS466_H.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

queue *initQ(node *data)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

header *initH()
{
    header *temp = (header *)malloc(sizeof(node));
    temp->start = NULL;
    temp->right = temp->down = NULL;
    return temp;
}

node *initN(int x, int y)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->down = temp->left = temp->right = temp->top = NULL;
    return temp;
}

void enqueue(queue **head, node *data)
{
    queue *temp = initQ(data);
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        queue *dummy = *head;
        while (dummy->link != NULL)
        {
            dummy = dummy->link;
        }
        dummy->link = temp;
    }
}

node *del_endqueue(queue **head)
{
    if (*head == NULL)
    {
        return NULL;
    }
    else
    {
        queue *dstart = *head;
        while (dstart->link->link != NULL)
            dstart = dstart->link;
        free(dstart->link);
        dstart->link = NULL;
        return dstart->data;
    }
}

node *dequeue(queue **head)
{
    queue *temp = *head;
    if (*head == NULL)
    {
        return NULL;
    }
    else
    {
        *head = (*head)->link;
        return temp->data;
    }
}

header *outline(int *en_x, int *en_y)
{
    header *head = initH();
    head->right = initH();
    head->down = initH();
    header *temp = NULL;
    header *hdown = head->down;
    header *hright = head->right;

    for (int i = 0; i <= *en_y; i++)
    {
        temp = initH();
        hright->right = temp;
        hright = hright->right;
        // temp = NULL;
    }
    for (int j = 0; j <= *en_x; j++)
    {
        temp = initH();
        hdown->down = temp;
        hdown = hdown->down;
        // temp = NULL;
    }
    return head;
}

header *link(header *head, int i, int j)
{
    node *temp = initN(i, j);
    node *dummy = NULL;
    header *hright = head->right;
    header *hdown = head->down;
    for (int k = 0; k < j; k++)
    {
        hright = hright->right;
    }
    if (hright->start == NULL)
    {
        hright->start = temp;
    }
    else
    {
        dummy = hright->start;
        while (dummy->down != NULL)
        {
            dummy = dummy->down;
        }
        dummy->down = temp;
        temp->top = dummy;
    }

    for (int k = 0; k < i; k++)
    {
        hdown = hdown->down;
    }
    if (hdown->start == NULL)
    {
        hdown->start = temp;
    }
    else
    {
        dummy = hdown->start;
        while (dummy->right != NULL)
        {
            dummy = dummy->right;
        }
        dummy->right = temp;
        temp->left = dummy;
    }
    return head;
}

header *readMap(int *st_x, int *st_y, int *en_x, int *en_y)
{
    FILE *ptr;
    header *map = NULL;
    int i = 0, j = 0;
    char start[10], end[10], str[100];
    ptr = fopen("input.txt", "r");
    fgets(start, 10, ptr);
    fgets(end, 10, ptr);
    *st_x = start[0] - 48;
    *st_y = start[2] - 48;
    *en_x = end[0] - 48;
    *en_y = end[2] - 48;
    map = outline(en_x, en_y);
    while (fgets(str, 100, ptr) != NULL)
    {
        for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == '0')
            {
                map = link(map, i, j / 2);
            }
        }
        i++;
    }
    fclose(ptr);
    printf("Read the layout into multilist\n");
    return map;
}

queue *findPath(header *head, int start_x, int start_y, int end_x, int end_y)
{
    node *temp = head->start;
    // printf("%d\t%d\n", dummy->x, dummy->y);
    queue *q = NULL;
    // enqueue(&q, temp);
    while (temp->left != NULL || temp->top != NULL || (temp->x == 0 && temp->y == 0))
    {
        if (temp->x == end_x && temp->y == end_y)
        {
            printf("Path found\nWriting the path into 'out.txt'\n");
            enqueue(&q, temp);
            return q;
        }
        else if (temp->right != NULL && temp->right->y <= end_y && (temp->y - temp->right->y) == -1)
        {
            // printf("Current coordinates:%d %d\nTook a right\n", temp->x, temp->y);
            enqueue(&q, temp);
            temp = temp->right;
        }
        else if (temp->down != NULL && temp->down->x <= end_x && (temp->x - temp->down->x) == -1)
        {
            // printf("Current coordinates:%d %d\nTook a down\n", temp->x, temp->y);
            enqueue(&q, temp);
            temp = temp->down;
        }
        else if ((temp->right == NULL || temp->down == NULL) || (temp->down->x - temp->x) > 1 && (temp->right->y - temp->y) > 1)
        {
            if ((temp->left)->y != (temp->y) - 1)
            {
                temp = temp->top->right;
            }
            else
            {
                temp = temp->left->down;
            }
            del_endqueue(&q);
        }
    }
    return NULL;
}

int storePath(header *head, int start_x, int start_y, int end_x, int end_y)
{
    queue *q;
    FILE *f = fopen("out.txt", "w");
    q = findPath(head, start_x, start_y, end_x, end_y);
    if (q == NULL)
    {
        printf("No path found\n");
        fprintf(f, "%d\n", -1);
        fclose(f);
        return -1;
    }
    node *out = dequeue(&q);
    while (out != NULL)
    {
        printf("Printing %d %d into file\n", out->x, out->y);
        fprintf(f, "%d %d\n", out->x, out->y);
        out = dequeue(&q);
    }
    fclose(f);
}
