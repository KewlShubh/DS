#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *lchild;
    struct tnode *rchild;
} tnode;

tnode *creatBST(tnode *root, int data)
{
    if (root == NULL)
    {
        root = (tnode *)malloc(sizeof(tnode));
        root->data = data;
        root->lchild = root->rchild = NULL;
    }
    else
    {
        if (data > root->data)
        {
            root->rchild = creatBST(root->rchild, data);
        }
        else
        {
            root->lchild = creatBST(root->lchild, data);
        }
    }
    return root;
}

void inorder(tnode *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

tnode *deleteBST(tnode *root, int key)
{
    if (root->data == key)
    {
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return NULL;
        }
        else if (root->lchild == NULL)
        {
            tnode *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            tnode *temp = root->lchild;
            free(root);
            return temp;
        }
        else
        {
            tnode *temp = root->rchild;
            while (temp->lchild != NULL)
            {
                temp = temp->lchild;
            }
            temp->lchild = root->lchild;
            temp = root->rchild;
            free(root);
            return temp;
        }
    }
    else
    {
        if (key > root->data)
        {
            root->rchild = deleteBST(root->rchild, key);
        }
        else
        {
            root->lchild = deleteBST(root->lchild, key);
        }
    }
}

int main()
{
    tnode *root = NULL;
    int check, data;

    while (1)
    {
        printf("\nEnter\n1. To insert\n2. To delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            root = creatBST(root, data);
            break;
        case 2:
            printf("Enter the data to be deleted: ");
            scanf("%d", &data);
            root = deleteBST(root, data);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}