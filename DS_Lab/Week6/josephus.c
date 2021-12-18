#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

void insert(node **s, int id)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = id;
    temp->link = NULL;
    if (*s == NULL)
    {
        *s = temp;
        temp->link = *s;
    }
    else
    {
        node *d = (*s)->link;
        while (d->link != *s)
        {
            d = d->link;
        }
        d->link = temp;
        temp->link = *s;
    }
}

void display(node *s)
{
    node *temp = s;
    do
    {
        printf("%d\t", s->data);
        s = s->link;
    } while (s != temp);
    printf("\n");
}

void process(node **s, int k)
{
    node *temp = *s;
    node *dummy = NULL;
    int i = 0;
    while (temp->link != temp)
    {
        for (i = 0; i < k - 1; i++)
        {
            temp = temp->link;
        }
        dummy = temp->link;
        temp->link = dummy->link;
        free(dummy);
        dummy = NULL;
        temp = temp->link;
    }
    *s = temp;
}

int main()
{
    node *no = NULL;
    int k, n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        insert(&no, i + 1);
    }
    process(&no, k - 1);
    display(no);
    return 0;
}