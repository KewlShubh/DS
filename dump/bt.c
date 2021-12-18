#include <stdio.h>
#include <stdlib.h>

int *init(int *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        t[i] = -1;
    }
}

/**I used a different variable here i.e. x.
 * This is because each time I called the function recursively, it wasnt getting updated.
 * Note: the int in = 1; has been removed. Tt wasnt getting incremented to its new value at all
 */
int *insert(int *t, int data, int x, int n)
{
    if (t[x] == -1)
    {
        t[x] = data; // t[1]=10
    }
    else
    {
        int l = 2 * x;     // l=2
        int r = 2 * x + 1; // r=3
        if (t[l] == -1)
        {
            t[l] = data;
            // t[2]=20
        }
        else if (t[r] == -1)
        {
            t[r] = data;
        }
        else
        {
            // This condition is used when l is greater than n
            if (l >= n)
            {
                x = l / 2;
                t = insert(t, data, x, n);
            }
            // This is when r is greater than n as well as insertion in the above function doesnt happen
            else if (r >= n)
            {
                x = (r - 1) / 2;
                t = insert(t, data, x, n);
            }
            else
            {
                /** This case we did not consider it last time
                 * Here l/r is less than n but insertion hasnt happened yet,
                 * so we need to call the insert function again.
                 * Now it works like pooooooof
                 */
                if (l < n)
                {
                    t = insert(t, data, l, n);
                }
                else if (r < n)
                {
                    t = insert(t, data, r, n);
                }
            }
        }
    }
    return t;
}

void preorder(int *t, int i, int n)
{
    if (t[i] != -1 && i < n)
    {
        printf("%d\t", t[i]);
        preorder(t, 2 * i, n);
        preorder(t, 2 * i + 1, n);
    }
}

int main()
{
    // int n;
    // printf("Enter the number of elements in the tree: ");
    // scanf("%d", &n);

    // Sorry for hardcoding values. It works without that also
    // I've added smol baby notes in insert function as well. Check them out as well hehe
    // Note: In functions init(), insert() as well as preorder, give the size of array as 'n' only and not n+1
    int *t = (int *)malloc((5) * sizeof(int));
    init(t, 5);
    t = insert(t, 10, 1, 5);
    t = insert(t, 1, 1, 5);
    t = insert(t, 50, 1, 5);
    t = insert(t, 70, 1, 5);
    preorder(t, 1, 5);
    // 4 values inserted with array space as 5. This is how you wanted alva babylove
    // i leeee wuuuu much muchh

    // t = insert(t, 30, in, 10);
    //  int c = 1;
    //  int data;

    /*while (c == 1)
    {
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        t = insert(t, data, in, n);
        printf("Enter 1 to insert more data: ");
        scanf("%d", &c);
    }
    t=insert(t,10,in);
    t=insert(t,20,in);
    t=insert(t,5,in);**/
    // preorder(t, 1, n);
}