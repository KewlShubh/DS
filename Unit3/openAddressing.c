#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int mark;
} node;

node *init()
{
    node *temp = (node *)malloc(sizeof(node) * 10);
    for (int i = 0; i < 10; i++)
    {
        temp[i].key = -1;
        temp[i].mark = 0;
    }
    return temp;
}

void insertLinear(node *head, int key)
{
    int index = key % 10;
    while (head[index].mark != 0)
    {
        index = (index + 1) % 10;
    }
    head[index].mark = 1;
    head[index].key = key;
}

void insertQuadruple(node *head, int key)
{
    int index = key % 10;
    int i = 0;
    while (head[index].mark != 0)
    {
        index = ((key % 10) + i * i) % 10;
        i++;
    }
    head[index].mark = 1;
    head[index].key = key;
}

void display(node *head)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", head[i].key);
    }
    printf("\n");
}

int main()
{
    node *head = init();
    insertQuadruple(head, 10);
    insertQuadruple(head, 20);
    insertQuadruple(head, 44);
    insertQuadruple(head, 34);
    insertQuadruple(head, 24);
    insertQuadruple(head, 7);
    display(head);
    return 0;
}