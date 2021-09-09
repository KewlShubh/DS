#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int front, int rear)
{
    if (front == rear)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            flip((str + front), (str + i));
            permute(str, front + 1, rear);
            flip((str + front), (str + i));
        }
    }
}

int main()
{
    char str[10] = "ABC";
    permute(str, 0, strlen(str) - 1);
}