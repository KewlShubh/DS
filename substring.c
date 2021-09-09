#include <stdio.h>
#include <stdlib.h>

int sub(char a[10], char b[10], int f1, int f2)
{
    if (b[f2] == '\0')
        return 1;
    else if (a[f1] == '\0')
        return 0;
    else
    {
        if (a[f1] == b[f2])
            return sub(a, b, f1 + 1, f2 + 1);
        else
            return sub(a, b, f1 + 1, 0);
    }
}

int main()
{
    char a[10], b[10];
    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);
    printf("%d", sub(a, b, 0, 0));
    return 0;
}