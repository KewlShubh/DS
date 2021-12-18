#include <stdio.h>
#include <stdlib.h>
#define max 3

void init_a(int a[max][max], int n)
{
    for (int i = 0; i < max; i++)
    {
        for(int j=0;j<max;j++)
        {
            a[i][j]=0;
        }
    }
}

void init_v(int *visited, int n)
{
    for (int i = 0; i < max; i++)
    {
        visited[i] = 0;
    }
}

void dfs(int a[max][max], int v, int *visited, int n)
{
    visited[v] = 1;
    printf("%d\t", v);
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            dfs(a, i, visited, n);
        }
    }
}

void DFS(int a[max][max], int v, int *visited, int n, int component)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(a, i, visited, n);
            component++;
        }
    }
    printf("\n");
    printf("Number of components through DFS: %d\n", component);
}

int connectivity(int a[max][max], int v, int *visited, int n)
{
    dfs(a, v, visited, n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            return -1;
        }
    }
    printf("\n");
    return 1;
}

int main()
{
    int visited[max];
    int a[max][max];
    int n;
    int c;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    // give n as 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter 1 if %d and %d are connected, else 0: ", i, j);
            scanf("%d", &c);
            a[i][j] = c;

        }
    }
    init_a(a,n);
    init_v(visited, n);
    DFS(a, 0, visited, max, 0);
    init_v(visited, n);
    int check=0;
    check = connectivity(a, 0, visited, max);
    if(check==1)
    {
        printf("Connected graph\n");
    }
    else
    {
        printf("Disconnected graph\n");
    }
    return 0;
}