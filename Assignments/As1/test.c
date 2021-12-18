#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int x;
    int y;
    struct Node *top;
    struct Node *down;
    struct Node *left;
    struct Node *right;
} node;

typedef struct queue
{
    node *data;
    struct queue *link;
} queue;

typedef struct header
{
    node *start;
    struct header *right;
    struct header *down;
} header;

queue *initQ(node *data)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

header *initH(node *data)
{
    header *temp = (header *)malloc(sizeof(node));
    temp->start = data;
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

node *dequeue(queue **head)
{
    queue *temp = *head;
    *head = (*head)->link;
    return temp->data;
}

void *insMap(header **head, node *temp)
{
    if (*head == NULL)
    {
        *head = initH(temp);
    }
    else
    {
        // printf("Reaching here\n");
        header *row, *col;
        row = *head;
        col = *head;
        header *create = NULL;
        int i;
        for (i = 0; i < temp->x; i++)
        {
            if (row->down == NULL)
            {
                create = initH(NULL);
                row->down = create;
                // free(create);
                create = NULL;
            }
            row = row->down;
        }
        for (i = 0; i < temp->y; i++)
        {
            if (col->right == NULL)
            {
                create = initH(NULL);
                col->right = create;
                // free(create);
                create = NULL;
            }
            col = col->right;
        }
        header *dummy;
        // printf("Up down linking\n");
        //  This is for up-down linking between nodes
        if (col->start == NULL)
        {
            col->start = temp;
        }
        for (i = 0; i < temp->x; i++)
        {
            if (col->down == NULL)
            {
                break;
            }
            else
            {
                dummy = col->down;
                if (dummy->start->x > temp->x)
                {
                    break;
                }
                else
                {
                    col = dummy;
                }
            }
        }
        create = initH(temp);
        if (col->down == NULL)
        {
            col->down = create;
            col->start->down = create->start;
            create->start->top = col->start;
        }
        else
        {
            create->down = col->down;
            col->down->start->top = create->start;
            create->start->down = col->down->start;
            col->down = create;
            create->start->top = col->start;
            col->start->down = create->start;
        }
        // printf("Up down linking ends\n");
        // printf("Left right linking \n");
        //  Up - down linking ends here

        // Left - right linking starts

        if (row->start == NULL)
        {
            row->start = temp;
        }
        for (i = 0; i < temp->y; i++)
        {
            if (row->right == NULL)
            {
                break;
            }
            else
            {
                dummy = row->right;
                if (dummy->start->y > temp->y)
                {
                    break;
                }
                else
                {
                    row = dummy;
                }
            }
        }
        create = initH(temp);
        if (row->right == NULL)
        {
            row->right = create;
            row->start->right = create->start;
            create->start->left = row->start;
        }
        else
        {
            create->right = row->right;
            row->right->start->left = create->start;
            create->start->right = row->right->start;
            row->right = create;
            create->start->left = row->start;
            row->start->right = create->start;
        }
        // printf("Left right linking ends\n");
        //  left-right linking ends
    }
}

header *readMap()
{
    FILE *ptr;
    header *map = NULL;
    int i = 0, j = 0;
    int st_x, st_y, en_x, en_y;
    char start[4], end[4], str[100];
    ptr = fopen("input.txt", "r");
    fgets(start, 4, ptr);
    fgets(end, 4, ptr);
    st_x = start[0] - 48;
    st_y = start[2] - 48;
    en_x = start[0] - 48;
    en_y = start[2] - 48;
    // printf("%d\t%d", st_x, st_y);
    //  insMap(&map, initN(0, 0));
    fgets(str, 100, ptr);
    while (fgets(str, 100, ptr) != NULL)
    {
        for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == '0')
            {
                insMap(&map, initN(i, j / 2));
                printf("%d %d\n", i, j / 2);
            }
        }
        i++;
    }
    // insMap(&map, initN(9, 9));
    fclose(ptr);
    return map;
}

queue *findpath(header *head, int start_x, int start_y, int end_x, int end_y)
{
    node *temp = head->start;
    node *dummy = temp->right;
    printf("%d\t%d\n", dummy->x, dummy->y);
    queue *q;
    while (temp->left != NULL && temp->top != NULL || (temp->x == 0 && temp->y == 0))
    {
        printf("Reached here\n");
        if (temp->x == end_x && temp->y == end_y)
        {
            printf("Destination reached\n");
            return q;
        }
        else if (temp->right != NULL && temp->right->y <= end_y && (temp->y - temp->right->y) == -1)
        {
            printf("took a right\n");
            enqueue(&q, temp);
            temp = temp->right;
        }
        else if (temp->down != NULL && temp->down->x <= end_x && (temp->x - temp->right->x) == -1)
        {
            printf("took a down\n");
            enqueue(&q, temp);
            temp = temp->down;
        }
        else if (temp->down == NULL && temp->right == NULL)
        {
            if ((temp->left)->y != (temp->y) - 1)
            {
                printf("took a top and right\n");
                temp = temp->top->right;
                dequeue(&q);
            }
            else
            {
                printf("took a left and down\n");
                temp = temp->left->down;
                dequeue(&q);
            }
        }
    }
    return NULL;
}

int write(header *head, int start_x, int start_y, int end_x, int end_y)
{
    queue *q;
    FILE *f = fopen("output.txt", "w");
    q = findpath(head, start_x, start_y, end_x, end_y);
    if (q == NULL)
    {
        printf("Oh no no path\n");
        fclose(f);
        return -1;
    }
    fprintf(f, "%d %d\n", start_x, start_y);
    fprintf(f, "%d %d\n", end_x, end_y);
    node *out = dequeue(&q);
    while (out != NULL)
    {
        fprintf(f, "%d %d\n", out->x, out->y);
        out = dequeue(&q);
    }
    fclose(f);
}

int main()
{
    header *head;
    printf("STarted\n");
    head = readMap();
    printf("Read\n");
    write(head, 0, 0, 9, 9);
    return 0;
}
