#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
void insert(NODE **dstart, int ele)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = ele;
    new_node->link = NULL;
    NODE *temp = *dstart;
    if (*dstart == NULL)
    {
        *dstart = new_node;
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
/*
void swapping(NODE* dstart,int n1,int n2)//n1 and n2 are the numbers that need to be swapped
{
    NODE *ptemp1,*ptemp2,*temp1,*temp2;
    

}*/

void delete_alternate(NODE **dstart)
{
    NODE *temp, *delnode;
    temp = *dstart;
    while (temp->link != NULL)
    {
        delnode = temp->link;
        if (temp->link->link != NULL)
        {
            temp->link = temp->link->link;
            temp = temp->link;
        }
        // Just added this condition for the code to work for even and odd number of elements
        else
        {
            temp->link = NULL;
        }
        free(delnode);
    }
}

void display(NODE *dstart)
{
    while (dstart != NULL)
    {
        printf("%d\t", dstart->data);
        dstart = dstart->link;
    }
    printf("\n");
}

int main()
{
    NODE *start = NULL;
    insert(&start, 10);
    insert(&start, 20);
    insert(&start, 30);
    insert(&start, 40);
    insert(&start, 50);
    display(start);
    delete_alternate(&start);
    display(start);
    return 0;
}
