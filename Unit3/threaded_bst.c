#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    int lthread;
    int rthread;
    struct tnode *lchild;
    struct tnode *rchild;
} tnode;

tnode *init(int data)
{
    tnode *temp = (tnode *)malloc(sizeof(tnode));
    temp->lchild = temp->rchild = NULL;
    temp->lthread = temp->rthread = 1;
    temp->data = data;
    return temp;
}

void createBST(tnode **root, int data)
{
    tnode *temp = init(data);
    if (*root == NULL)
    {
        *root = temp;
    }
    else
    {
        tnode *prev = *root;
        int flag = 0;
        while (flag == 0)
        {
            if (data > prev->data)
            {
                if (prev->rthread == 1)
                {
                    flag = 1;
                }
                else
                {
                    prev = prev->rchild;
                }
            }
            else
            {
                if (prev->lthread == 1)
                {
                    flag = 2;
                }
                else
                {
                    prev = prev->lchild;
                }
            }
        }
        if (flag == 1)
        {
            temp->lchild = prev;
            temp->rchild = prev->rchild;
            prev->rchild = temp;
            prev->rthread = 0;
        }
        else
        {
            temp->rchild = prev;
            temp->lchild = prev->lchild;
            prev->lchild = temp;
            prev->lthread = 0;
        }
    }
}

int main()
{
    tnode *root = NULL;
    createBST(&root, 10);
    createBST(&root, 50);
    createBST(&root, 1);
    return 0;
}