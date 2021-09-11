#include <stdio.h>
#include <stdlib.h>

struct matches
{
    int choice;
    int score;
};

typedef struct player
{
    char pname[20];
    char tname[20];
    struct matches m[14];
} player;

void insert(player **obj, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("Enter the Player name: ");
        scanf("%s", ((*obj) + i)->pname);
        printf("%s", *((*obj) + i)->pname);
        printf("Enter the Team name: ");
        scanf("%s", ((*obj) + i)->tname);
        for (int j = 0; j < 14; j++)
        {
            printf("Enter 'y' if player has played match %d followed by runs scored else 'n'\n", j + 1);
            //fflush(stdin);
            char c = getc(stdin);
            scanf("%c", ((*obj) + i)->m[j].choice);
            if (((*obj) + i)->m->choice == 'y')
            {
                scanf("%d", ((*obj) + i)->m[j].score);
            }
        }
    }
}

int main()
{
    int num = 2;
    player *obj;
    obj = (player *)malloc(2 * sizeof(player));
    for (int i = 0; i < num; i++)
    {
        printf("Enter the Player name: ");
        fflush(stdin);
        //gets((obj + i)->pname);
        scanf("%s", &(obj + i)->pname);
        fflush(stdin);
        //printf("%s", (obj + i)->pname);
        printf("Enter the Team name: ");
        //gets((obj + i)->tname);
        scanf("%s", &(obj + i)->tname);
        fflush(stdin);
        for (int j = 0; j < 14; j++)
        {
            printf("Enter\n 1 if player has played match %d followed by runs scored else enter 0: ", j + 1);
            //(obj + i)->m[j].choice = getc(stdin);
            scanf("%d", &(obj + i)->m[j].choice);
            fflush(stdin);
            //char c = getc(stdin);
            //fflush(stdin);
            //printf("%c", (obj + i)->m->choice);
            if ((obj + i)->m[j].choice == 1)
            {
                scanf("%d", &(obj + i)->m[j].score);
                fflush(stdin);
            }
            else
            {
                (obj + i)->m[j].score = -1;
            }
        }
    }
    return 0;
}