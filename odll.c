#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *name;
    char *address;
    char *area;
    int pno;
    struct Node *llink, *rlink;
} Node;

typedef struct CustomerDetails
{
    Node *head;
} CustomerDetails;

void insert(CustomerDetails *p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->name = (char *)malloc(20 * sizeof(char));
    temp->address = (char *)malloc(50 * sizeof(char));
    temp->area = (char *)malloc(50 * sizeof(char));
    printf("Enter name: ");
    scanf("%s", temp->name);
    printf("Enter address: ");
    scanf("%s", temp->address);
    printf("Enter area: ");
    scanf("%s", temp->area);
    printf("Enter phone number: ");
    scanf("%d", &temp->pno);
    temp->llink = temp->rlink = NULL;
    if (p->head == NULL)
    {
        p->head = temp;
    }
    else
    {
        Node *dstart = p->head;
        while (dstart->rlink != NULL)
        {
            if (strcmp(dstart->name, temp->name) > 0)
            {
                if (dstart->llink == NULL)
                {
                    temp->rlink = dstart;
                    dstart->llink = temp;
                    p->head = temp;
                }
                else
                {
                    temp->rlink = dstart;
                    temp->llink = dstart->llink;
                    dstart->llink->rlink = temp;
                    dstart->llink = temp;
                }
                break;
            }
            dstart = dstart->rlink;
        }
        if (dstart->rlink == NULL && dstart->llink != NULL)
        {
            if (strcmp(dstart->name, temp->name) > 0)
            {
                temp->rlink = dstart;
                temp->llink = dstart->llink;
                dstart->llink->rlink = temp;
                dstart->llink = temp;
            }
            else
            {
                dstart->rlink = temp;
                temp->llink = dstart;
            }
        }

        else if (dstart->llink == NULL)
        {
            temp->rlink = dstart;
            dstart->llink = temp;
            p->head = temp;
        }
    }
}

void display(CustomerDetails p)
{
    while (p.head != NULL)
    {
        printf("%s\t%s\t%s\t%d\n", p.head->name, p.head->address, p.head->area, p.head->pno);
        p.head = p.head->rlink;
    }
}

int main()
{
    CustomerDetails p;
    p.head = NULL;
    Node *head = NULL;
    insert(&p);
    insert(&p);
    insert(&p);
    display(p);
    return 0;
}