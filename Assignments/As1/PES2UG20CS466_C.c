#include "PES2UG20CS466_H.h"

int main()
{
    header *head;
    int a = 0, b = 0, c = 0, d = 0;
    head = readMap(&a, &b, &c, &d);
    storePath(head->right, a, b, c, d);
    return 0;
}