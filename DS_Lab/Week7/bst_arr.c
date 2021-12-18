#include <stdio.h>
#include <stdlib.h>

int *init(int *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        t[i] = -1;
    }
    return t;
}

int *insert(int *t, int data, int n)
{
    if (t[0] == -1)
    {
        t[0] = data;
    }
    else
    {
        int i = 0;
        while (t[i] != -1)
        {
            if (data > t[i])
                i = 2 * i + 2;
            else
                i = 2 * i + 1;
        }
        t[i] = data;
    }
    return t;
}

int level(int *t)
{
    if (t[0] == -1)
    {
        return 0;
    }
    else
    {
        int l = 0, i = 0, r = 0;
        while (i < 10)
        {
            if (t[2 * i + 1] == -1 && t[2 * i + 2] == -1)
            {
                break;
            }
            else
            {
                if (t[2 * i + 1] == -1)
                {
                    i = 2 * i + 2;
                }
                else
                {
                    i = 2 * i + 1;
                }
            }
            l++;
        }
        i = 0;
        while (i < 10)
        {
            if (t[2 * i + 1] == -1 && t[2 * i + 2] == -1)
            {
                break;
            }
            else
            {
                if (t[2 * i + 2] == -1)
                {
                    i = 2 * i + 1;
                }
                else
                {
                    i = 2 * i + 2;
                }
            }
            r++;
        }
        if (l > r)
        {
            printf("The height is %d\n", l + 1);
        }
        else
        {
            printf("The height is %d\n", r + 1);
        }
    }
}

int main()
{
    int *t = (int *)malloc(sizeof(int) * 20);
    t = init(t, 20);
    t = insert(t, 10, 20);
    t = insert(t, 5, 20);
    t = insert(t, 20, 20);
    t = insert(t, 30, 20);
    t = insert(t, 2, 20);
    t = insert(t, 6, 20);
    /*for (int i = 0; i < 20; i++)
    {
        printf("%d\t", t[i]);
    }*/
    printf("\n");
    //printf("%d", t[2]);
    level(t);
    //printf("%d", level(t));
    return 0;
}