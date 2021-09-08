#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *link;
} node;

void insert(node **head, int ele)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = ele;
    new_node->link = NULL;
    node *temp = *head;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void display(node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->link;
    }
    printf("\n");
}

node *del_alt(node *head)
{
    node *temp = head;
    head = head->link;
    free(temp);
    node *del = NULL;
    temp = head;
    //printf("\n%d\t%d\n", head->data, temp->data);
    while (temp != NULL && temp->link != NULL)
    {
        del = temp->link;
        //printf("%d\t", del->data);
        temp->link = temp->link->link;
        temp = temp->link;
        free(del);
    }
    return head;
}

void swap(node **head, int a, int b)
{
    node *d1, *d2, *p1, *p2;
    d1 = d2 = *head;
    p1 = p2 = NULL;
    int flag = -1;
    while (d1 != NULL && d2 != NULL)
    {
        if (d1->data == a && d2->data == b)
        {
            flag = 0;
            break;
        }
        else if (d1->data == a && d2->data != b)
        {
            p2 = d2;
            d2 = d2->link;
        }
        else if (d1->data != a && d2->data == b)
        {
            p1 = d1;
            d1 = d1->link;
        }
        else
        {
            p2 = d2;
            d2 = d2->link;
            p1 = d1;
            d1 = d1->link;
        }
    }
    if (flag == 0)
    {
        if (p1 != NULL)
        {
            p2->link = d1;
            p1->link = d2;
            node *temp = d2->link;
            d2->link = d1->link;
            d1->link = temp;
        }
        else if (p1 == NULL)
        {
            p2->link = d1;
            node *temp = d2->link;
            d2->link = d1->link;
            d1->link = temp;
            *head = d2;
        }
    }
    else
    {
        printf("Nodes not found :(\n");
    }
}

int main()
{
    node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    swap(&head, 20, 40);
    display(head);
    //head = del_alt(head);
    //display(head);
    return 0;
}