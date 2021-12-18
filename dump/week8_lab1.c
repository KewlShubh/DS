#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *rchild;
    struct node *lchild;
}node;

node *insert(node *root, int info)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=info;
        root->lchild=root->rchild=NULL;
    }
    else 
    {
        if(info>root->data)
        {
            root->rchild=insert(root->rchild,info);
        }
        else
        {
            root->lchild=insert(root->lchild,info);
        }
    }
    return root;
}

void display(node *root)
{
    if(root!=NULL)
    {
        display(root->lchild);
        printf("%d\t",root->data);
        display(root->rchild);
    }
}

node *delete(node *root, int data)
{
    node *pres=root;
    node *prev=NULL;
    if(pres->data==data)
    {
        if(pres->lchild==NULL && pres->rchild==NULL)
        {
            free(pres);
        }
        else if(pres->rchild==NULL)
        {
            prev=pres;
            pres=pres->lchild;
            free(prev);
        }
        else if(pres->lchild==NULL)
        {
            prev=pres;
            pres=pres->rchild;
            free(prev);
        }
        else
        {
            node *s=NULL;
            node *pres=root;
            node *temp=root;
            temp=temp->rchild;
            while(temp->lchild!=NULL)
            {
                temp=temp->lchild;
            }
            s->data=pres->data;
            pres->data=temp->data;
            temp->data=s->data;
            root=delete(root,data);
        }
    }
}

int main()
{
    node *root=NULL;
    int c;
    int data;
    while(1)
    {
        printf("1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {   
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            }
            case 2:
            {
                display(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Enter the data to be deleted: ");
                scanf("%d",&data);
                delete(root,data);
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}

