#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} node;

node *insert()
{
    int ele;
    printf("Enter any number: ");
    scanf("%d", &ele);
    if (ele == -1)
    {
        return NULL;
    }
    else
    {
        node *p = (node *)malloc(sizeof(node));
        p->data = ele;
        printf("Enter the lchild of %d:\n", ele);
        p->lchild = insert();
        printf("Enter the rchild of %d:\n", ele);
        p->rchild = insert();
        return p;
    }
}

/*node *mirrcopy(node *start)
{
    if (start == NULL)
    {
        return NULL;
    }
    else
    {
        node *end = (node *)malloc(sizeof(node));
        end->data = start->data;
        end->lchild = mirrcopy(start->rchild);
        end->rchild = mirrcopy(start->lchild);
        return end;
    }
}
*/
node *mirror(node *root1, node *root2)
{
    if (root1 == NULL)
    {
        return root1;
    }
    else
    {
        root2 = insert(root2, root1->data);
        root2->lchild = mirror(root1->rchild, root2->lchild);
        root2->rchild = mirror(root1->lchild, root2->rchild);
    }
    return root2;
}

void inorder(node *root)
{
    if (root == NULL)
    {
    }
    else
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

int comp(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    else if (b >= c && b >= a)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int max(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->lchild == NULL && root->rchild == NULL)
    {
        return root->data;
    }
    else
    {
        int x, y;
        x = max(root->lchild);
        y = max(root->rchild);
        return comp(x, y, root->data);
    }
}

int height(node *root, int h)
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
        return comp(x, y, -1);
    }
}

int check(node *root)
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

int main()
{
    node *root = NULL, *end = NULL;
    root = insert();
    end = mirror(root, end);
    inorder(root);
    printf("\n");
    inorder(end);
    printf("\n");
    // printf("%d\n", max(root));
    // printf("%d\n", height(root, 0));
    printf("%d", check(root));
    return 0;
}
