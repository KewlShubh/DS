#include <stdio.h>

void hanoi_work(int n, char start, char end, char temp)
{
    if (n == 1)
    {
        printf("Move Disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    else
    {
        hanoi_work(n - 1, start, temp, end);
        printf("Move Disk %d from rod %c to rod %c\n", n, start, end);
        hanoi_work(n - 1, temp, end, start);
    }
}

int main()
{
    int n; //Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi_work(n, 'A', 'C', 'B'); //A is the starting rod, B the intermediate rod and C the end rod
    return 0;
}