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
        //printf("%s", *((*obj) + i)->pname);
        printf("Enter the Team name: ");
        scanf("%s", ((*obj) + i)->tname);
        for (int j = 0; j < 14; j++)
        {
            printf("Enter '1' if player has played match %d followed by runs scored else '0'\n", j + 1);
            //fflush(stdin);
            //char c = getc(stdin);
            scanf("%d", ((*obj) + i)->m[j].choice);
            if (((*obj) + i)->m->choice == 1)
            {
                scanf("%d", ((*obj) + i)->m[j].score);
            }
        }
    }
}

int main()
{
    int num;
    player *obj;
    printf("Enter the number of players: ");
    scanf("%d", &num);
    fflush(stdin);
    obj = (player *)malloc(num * sizeof(player));

    for (int i = 0; i < num; i++)
    {
        printf("Enter the Player name: ");
        fflush(stdin);
        scanf("%s", &(obj + i)->pname);
        fflush(stdin);
        printf("Enter the Team name: ");
        scanf("%s", &(obj + i)->tname);
        fflush(stdin);
        for (int j = 0; j < 14; j++)
        {
            printf("Enter 1 if player has played match %d followed by runs scored else enter 0: ", j + 1);
            scanf("%d", &(obj + i)->m[j].choice);
            fflush(stdin);
            if ((obj + i)->m[j].choice == 1)
            {
                printf("Enter the runs: ");
                scanf("%d", &(obj + i)->m[j].score);

                fflush(stdin);
            }
            else
            {
                (obj + i)->m[j].score = -1;
            }
        }
    }

    //To find the highest scorer in a particular match
    int match;
    printf("Enter the Match number to find out the highest run scorer: ");
    scanf("%d", &match);
    match -= 1;
    int pos = 0;
    for (int i = 1; i < num; i++)
    {
        if ((obj + i)->m[match].score > (obj + pos)->m[match].score)
        {
            pos = i;
        }
    }

    printf("Details of Highest Runs Scorer\nName: %s\nTeam name: %s\nRuns Scored: %d\n\n", (obj + pos)->pname, (obj + pos)->tname, (obj + pos)->m[match].score);

    //Computing Number of matches played by each player
    for (int i = 0; i < num; i++)
    {
        int matches = 0;
        for (int j = 0; j < 14; j++)
        {
            if ((obj + i)->m[j].choice == 1)
                matches++;
        }

        printf("The number of matches played by %s is %d\n", (obj + i)->pname, matches);
    }
    return 0;
}