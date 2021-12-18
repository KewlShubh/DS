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
        printf("Enter the name of Player %d: ", i + 1);
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
            printf("\n");
        }
    }

    //To find the highest scorer in a particular match
    int match;
    printf("------------------------------------------------------------\n");
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

    printf("\nDetails of Highest Runs Scorer\nName: %s\nTeam name: %s\nRuns Scored: %d\n\n", (obj + pos)->pname, (obj + pos)->tname, (obj + pos)->m[match].score);
    printf("------------------------------------------------------------\n");
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