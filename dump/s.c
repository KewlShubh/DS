#include <stdio.h>
#include <stdlib.h>
void insert(int ele);
void delete ();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    printf("After deleting alternate node:\n");
    delete ();
    display();
    printf("After deleting alternate node:\n");
    delete ();
    display();
}
void insert(int ele)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    new->data = ele;
    if (temp == NULL)
    {
        head = new;
        new->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete ()
{
    struct node *temp;
    struct node *del;
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    del = NULL;
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        del = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(del);
        del = NULL;
    }
}