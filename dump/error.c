#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rec_substr(char *main, char *target, int target_length)
{
    if (strlen(main) < target_length)
    {
        return 0;
    }
    else
    {
        int found = strncmp(main, target, target_length);
        if (found != 0)
        {
            return rec_substr(main + 1, target, target_length);
        }
        else
        {
            return 1;
        }
    }
}

int main()
{
    char a[10] = "Shubh";
    char b[10] = "hu";
    printf("%d", rec_substr(a, b, 2));
}