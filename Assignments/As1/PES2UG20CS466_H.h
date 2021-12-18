#ifndef DS_H
#define DS_H

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

queue *initQ(node *data);
header *initH();
node *initN(int x, int y);
void enqueue(queue **head, node *data);
node *dequeue(queue **head);
header *outline(int *en_x, int *en_y);
header *link(header *head, int i, int j);
header *readMap(int *st_x, int *st_y, int *en_x, int *en_y);
queue *findPath(header *head, int start_x, int start_y, int end_x, int end_y);
int storePath(header *head, int start_x, int start_y, int end_x, int end_y);

#endif