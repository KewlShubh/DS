#include <stdio.h>
#include <stdlib.h>

void insert(int ele);
void display();
void swap();
//void delete();

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
    swap();
    printf("Nodes after swapping: \n");
    display();
    //delete();
    return 0;
}

void insert(int ele)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    new->data = ele;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
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

void swap()
{
    struct node *pres1;
    struct node *pres2;
    struct node *prev1;
    struct node *prev2;
    struct node *temp1;
    struct node *temp2;
    temp1 = NULL;
    prev1 = NULL;
    prev2 = NULL;
    pres1 = head;
    pres2 = head;
    temp2 = head;
    int pos1;
    int pos2;
    printf("Enter the first node to swap: ");
    scanf("%d", &pos1);
    printf("Enter the second node to swap: ");
    scanf("%d", &pos2);
    int i = 0;
    while (i != pos1)
    {
        prev1 = pres1;
        pres1 = pres1->next;
        printf("First while");
        i++;
    }
    i = 0;
    while (i != pos2)
    {
        prev2 = pres2;
        pres2 = pres2->next;
        printf("Second while");
        i++;
    }
    temp1 = pres2->next;
    prev1->next = pres2;
    pres2->next = pres1->next;
    prev2->next = pres1;
    pres1->next = temp1;
    //printf("Nodes after swapping: \n");
    /*while (temp2 != NULL)
    {
        printf("%d\n", temp2->data);
        temp2 = temp2->next;
    }*/
}