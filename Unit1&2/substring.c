#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ssub(char *a, char *b, int length)
{
    if (strlen(a) == 0)
    {
        return 0;
    }
    else
    {
        if (strncmp(a, b, length) == 0)
        {
            return 1;
        }
        else
        {
            ssub(a + 1, b, length);
        }
    }
}

int main()
{
    char a[10], b[10];
    printf("Enter the first string: ");
    gets(a);
    printf("Enter the second string: ");
    gets(b);
    //scanf("%s", b);
    if (ssub(a, b, strlen(b)))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}
