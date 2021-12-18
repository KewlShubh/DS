#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie
{
    struct trie *child[26];
    int isEnd;
} trie;

trie *newNode()
{
    trie *temp = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    temp->isEnd = 0;
    return temp;
}

trie *insertNode(trie *root, char *str)
{
    trie *current = root;
    int index, i;
    for (i = 0; str[i] != '\0'; i++)
    {
        index = str[i] - 'a';
        if (current->child[index] == NULL)
        {
            current->child[index] = newNode();
        }
        current = current->child[index];
    }
    current->isEnd = 1;
    return root;
}

int searchNode(trie *root, char *str, char *check, int length)
{
    int cur;
    if (root != NULL && root->isEnd == 1)
    {
        check[length] = '\0';
        if (!strcmp(str, check))
        {
            printf("String found\n");
            return 1;
        }
    }
    else
    {
        cur = str[length] - 'a';
        if (root->child[cur] != NULL)
        {
            check[length] = cur + 'a';
            searchNode(root->child[cur], str, check, length + 1);
        }
        else
        {
            printf("No string found\n");
            return -1;
        }
    }
}

trie *deleteNode(trie *root, char *str)
{
}

void display(trie *root, char *str, int level)
{
    if (root->isEnd == 1)
    {
        str[level] = '\0';
        printf("%s\n", str);
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->child[i] != NULL)
            {
                str[level] = i + 'a';
                display(root->child[i], str, level + 1);
            }
        }
    }
}

int main()
{
    trie *root = newNode();
    char str[100];
    char check[100];
    root = insertNode(root, "ana");
    root = insertNode(root, "anana");
    root = insertNode(root, "hola");
    root = insertNode(root, "banaa");
    display(root, str, 0);
    searchNode(root, "banana", check, 0);
    return 0;
}