#include <stdio.h>
#include <stdlib.h>

int *insHeap(int *H, int n)
{
    int p, c, key;
    for (p = (n / 2) - 1; p >= 0; p--)
    {
        key = H[p];
        c = p * 2 + 1;
        while (c < n)
        {
            if (H[c + 1] < H[c] && c < n - 1)
                c = c + 1;

            if (H[c] < key)
            {
                H[p] = H[c];
            }
            else
            {
                break;
            }
            p = c;
            c = p * 2 + 1;
        }
        H[p] = key;
    }
    return H;
}

int *delHeap(int *H, int n)
{
    H[0] = H[n - 1];
    return insHeap(H, n);
}

void display(int *H, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", H[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int *H;
    H = insHeap(&(a[0]), 5);
    display(H, 5);
    // H = delHeap(&(a[0]), 5);
    // display(H, 4);
    return 0;
}