#include <stdio.h>
#include <stdlib.h>

/**
 * Hashing using Seperate chaining
 **/

typedef struct node
{
    int key;
    struct node *next;
} node;

typedef struct hash
{
    node *start;
    int count;
} hash;

node *createNode(int key)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

hash *init(hash *head)
{
    head = (hash *)malloc(sizeof(hash) * 10);
    for (int i = 0; i < 10; i++)
    {
        head[i].count = 0;
        head[i].start = NULL;
    }
    return head;
}

void insert(hash *head, int key)
{
    int index = key % 10;
    node *temp = createNode(key);
    if (head[index].start != NULL)
    {
        temp->next = head[index].start;
    }
    head[index].start = temp;
    head[index].count++;
}

void display(hash *head)
{
    node *temp;
    for (int i = 0; i < 10; i++)
    {
        printf("List %d:\t", i);
        temp = head[i].start;
        while (temp != NULL)
        {
            printf("%d\t", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(hash *head, int key)
{
}

int main()
{
    hash *head = init(head);
    insert(head, 5);
    insert(head, 35);
    insert(head, 51);
    insert(head, 41);
    insert(head, 3);
    display(head);
    return 0;
}