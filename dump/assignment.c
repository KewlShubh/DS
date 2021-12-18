/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct details
{
    char part[10];
    int runs;
} match;

typedef struct player
{
    char p_name[50];
    char t_name[50];
    match m[15];
} player;
void main()
{
    int num = 0;
    int max = 0, k = 0, count = 0;
    printf("PLEASE ENTER THE NUMBER OF PLAYERS U WANT\n");
    scanf("%d", &num);
    int matches[num];
    player obj[num];
    for (int i = 0; i < num; i++)
    {
        int k = 0;
        printf("Plese enter the name of the player\n");
        scanf("%s", obj[i].p_name);
        printf("Plese enter the name of the team\n");
        scanf("%s", obj[i].t_name);
        for (int j = 0; j < 14; j++)
        {
            printf("Plese enter if the player played the match(Y\\N)\n");
            scanf("%s", obj[i].m[j].part);
            if (strcmp(obj[i].m[j].part, "Y") == 0)
            {
                k++;
            }
            printf("Plese enter the runs scored by the player\n");
            scanf("%d", &obj[i].m[j].runs);
        }
        matches[i] = k;
    }
    system("cls");
    printf("The player with max runs in each match is: \n");
    for (int j = 0; j < 14; j++)
    {
        for (int i = 0; i < num; i++)
        {

            if (obj[i].m[j].runs > max)
            {
                count = i;
            }
            max = obj[i].m[j].runs;
        }
        printf("Player: %s\n Team name: %s\n scored highest in match %d\n", obj[count].p_name, obj[count].t_name, j + 1);
    }
    for (int i = 0; i < num; i++)
    {
        printf("player %s played %d matches\n", obj[i].p_name, matches[i]);
    }
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *name;

    int p_n;
    char *address;
    char *area;
    struct node *next;
    struct node *prev;
} node;
typedef struct c_d
{
    node *head;
} cd;
node *create(char *name, char *address, char *area, int p_n, node *next, node *prev)
{
    node *temp = malloc(sizeof(node));
    temp->name = name;
    temp->address = address;
    temp->area = area;
    temp->p_n = p_n;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
node *ordered(cd c, node *temp)
{
    node *buffer;
    node *dstart = c.head;
    if (c.head == NULL)
    {
        c.head = temp;
    }
    else
    {
        while (strcmp(dstart->name, temp->name) < 0 && dstart->next != NULL)
        {
            dstart = dstart->next;
        }
        if (dstart == c.head && strcmp(dstart->name, temp->name) > 0)
        {
            temp->next = dstart;
            dstart->prev = temp;
            c.head = temp;
        }
        else if (dstart == c.head && strcmp(dstart->name, temp->name) < 0)
        {
            temp->prev = dstart;
            dstart->next = temp;
        }
        else if (dstart == NULL)
        {
            temp->prev = dstart;
            dstart->next = temp;
        }
        else
        {
            buffer = dstart->prev;
            temp->next = dstart;
            temp->prev = buffer;
            buffer->next = temp;
        }
    }
    return c.head;
}
void display(cd c)
{
    while (c.head != NULL)
    {
        printf("NAME: %s\n", c.head->name);
        c.head = c.head->next;
    }
}
int main()
{
    int num;
    char *name = malloc(50 * sizeof(char));
    char *address = malloc(50 * sizeof(char));
    char *area = malloc(50 * sizeof(char));
    int p_n;
    node *next, *prev;
    cd c;
    c.head = NULL;
    node *temp;
    while (1 != 0)
    {

        printf("1.INSERT\n2.DISPLAY\n3.EXIT\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Please enter the details:\n");
            scanf("%s", name);
            scanf("%s", address);
            scanf("%s", area);
            scanf("%d", &p_n);
            temp = create(name, address, area, p_n, next, prev);
            c.head = ordered(c, temp);
            break;
        case 2:
            display(c);
            break;
        case 3:
            exit(0);
        }
    }
}
