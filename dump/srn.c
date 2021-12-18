#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    char *SRN;
    struct tree *lchild;
    struct tree *rchild;
} tree;

struct tree *newNode(char *item)
{
    // printf("%s", item);
    struct tree *temp = (struct tree *)malloc(sizeof(tree));
    temp->SRN = item;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void inorder(struct tree *root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%s \n", root->SRN);
        inorder(root->rchild);
    }
}
struct tree *insert(struct tree *node, char *item)
{
    if (node == NULL)
    {
        return newNode(item);
    }
    if (strcmp(item, node->SRN) < 0)
    {
        // printf("%d", strcmp(item, node->SRN));
        node->lchild = insert(node->lchild, item);
    }
    else if (strcmp(item, node->SRN) > 0)
    {
        node->rchild = insert(node->rchild, item);
    }
    return node;
}
void main()
{
    struct tree *root = NULL;
    int n;
    char *s;
    printf("Enter the number of people : ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter SRN of Person %d : ", (i + 1));
        scanf("%s", s);
        printf("%s", s);
        root = insert(root, s);
    }
    inorder(root);
}