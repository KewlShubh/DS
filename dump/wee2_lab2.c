#include <stdio.h>
#include <stdlib.h>
void insert1();
void insert2();
struct node
{
    int c;
    int px;
    int py;
    struct node *next;
};
struct node *head = NULL;
struct node *head2 = NULL;
int main()
{
    printf("For linked list 1\n");
    insert1();
    insert1();
    insert1();
    printf("For linked list 2\n");
    insert2();
    insert2();
    insert2();
}
void insert1()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    int co, p1, p2;
    printf("Enter the coefficient: ");
    scanf("%d", &co);
    printf("Enter the power of x: ");
    scanf("%d", &p1);
    printf("Enter the power of y: ");
    scanf("%d", &p2);
    new->c = co;
    new->px = p1;
    new->py = p2;
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
void insert2()
{
    struct node *new2 = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head2;
    int co, p1, p2;
    printf("Enter the coefficient: ");
    scanf("%d", &co);
    printf("Enter the power of x: ");
    scanf("%d", &p1);
    printf("Enter the power of y: ");
    scanf("%d", &p2);
    new2->c = co;
    new2->px = p1;
    new2->py = p2;
    if (temp == NULL)
    {
        head2 = new2;
        new2->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new2;
        new2->next = NULL;
    }
}
