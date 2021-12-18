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

int check(tnode *root)
{
    if (root->lchild == root->rchild)
    {
        return 1;
    }
    else if (root->lchild == NULL)
    {
        if (root->data > root->rchild->data)
        {
            return -1;
        }
        else
        {
            return (check(root->rchild));
        }
    }
    else if (root->rchild == NULL)
    {
        if (root->data < root->lchild->data)
        {
            return -1;
        }
        else
        {
            return (check(root->lchild));
        }
    }
    else
    {
        int x, y;
        x = check(root->lchild);
        y = check(root->rchild);
        if (x == 1 && y == 1)
        {
            if (root->lchild->data < root->data && root->data < root->rchild->data)
            {
                return 1;
            }
        }
        return -1;
    }
}

int comp(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

tnode *copy(tnode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        tnode *croot = (tnode *)malloc(sizeof(tnode));
        croot->lchild = copy(root->lchild);
        croot->data = root->data;
        croot->rchild = copy(root->rchild);
        return croot;
    }
}

tnode *mir_copy(tnode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        tnode *mir = (tnode *)malloc(sizeof(tnode));
        mir->data = root->data;
        mir->rchild = mir_copy(root->lchild);
        mir->lchild = mir_copy(root->rchild);
        return mir;
    }
}

int compare(tnode *root, tnode *croot)
{
    if (root == NULL && croot == NULL)
    {
        return 1;
    }
    else if (root == NULL || croot == NULL)
    {
        return 0;
    }
    else
    {
        int x = compare(root->lchild, croot->lchild);
        int y = compare(root->rchild, croot->rchild);
        if (x == 1 && y == 1 && root->data == croot->data)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int height(tnode *root, int h)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->lchild == NULL && root->rchild == NULL)
    {
        return h + 1;
    }
    else
    {
        int x, y;
        x = height(root->lchild, h + 1);
        y = height(root->rchild, h + 1);
        return comp(x, y);
    }
}

int main()
{
    tnode *root = NULL, *croot;
    root = creatBST(root, 10);
    root = creatBST(root, 5);
    root = creatBST(root, 15);
    root = creatBST(root, 1);
    root = creatBST(root, 20);
    root = creatBST(root, 30);
    croot = NULL;
    inorder(root);
    printf("\n");
    croot = mir_copy(root);
    inorder(croot);
    printf("\n");
    // printf("%d\n", compare(root, croot));

    return 0;
}