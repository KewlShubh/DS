#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct N
{
    char *name;
    int phone_number;
    char *address;
    char *area;
    struct N *next, *prev;
} Node;

typedef struct CD
{
    Node *head;
} CustomerDetails;

void insert(CustomerDetails *ob);
void display(CustomerDetails *ob);
void sort(CustomerDetails *ob);

int main()
{
    CustomerDetails ob;
    int c;
    do
    {
        insert(&ob);
        printf("Enter 1 to insert more nodes, else enter 0: ");
        scanf("%d", &c);
    } while (c == 1);
    display(&ob);
    //sort(&ob);
    printf("After sorting:\n");
    display(&ob);
}
void insert(CustomerDetails *ob)
{
    Node *new = (Node *)malloc(sizeof(Node));
    Node *temp;
    ob->head = NULL;
    //allocating memory
    new->name = (char *)malloc(10 * sizeof(char));
    new->address = (char *)malloc(50 * sizeof(char));
    new->area = (char *)malloc(50 * sizeof(char));

    //accepting values
    printf("Enter the name: ");
    scanf("%s", new->name);
    printf("Enter the number: ");
    scanf("%d", &new->phone_number);
    printf("Enter the address: ");
    scanf("%s", new->address);
    printf("Enter the area: ");
    scanf("%s", new->area);
    if (ob->head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        ob->head = new;
    }
    else
    {
        temp = ob->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        new->prev = temp;
    }
}

void display(CustomerDetails *ob)
{
    Node *temp;
    temp = ob->head;
    while (temp != NULL)
    {
        printf("Name : %s\n", temp->name);
        printf("Number : %d\n", temp->phone_number);
        printf("Address : %s\n", temp->address);
        printf("Area : %s\n", temp->area);
        temp = temp->next;
    }
}

void sort(CustomerDetails *ob)
{
    Node *temp;
    Node *after;
    after = NULL;
    temp = ob->head;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    while (temp->next != NULL)
    {
        if (strcmp(temp->name, temp->next->name) > 0)
        {
            after = temp->next;
            temp->next = after->next;
            after->prev = NULL;
            after->next = temp;
            temp->prev = after;
        }
    }
}