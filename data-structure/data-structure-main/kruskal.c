#include <stdio.h>
#include <limits.h>
#define MAX 100

int n;
int parent[MAX];
int adj[MAX][MAX];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}
int kruskal()
{
    int edgesUsed = 0;
    int totalcost = 0;
    while (edgesUsed < n - 1)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (find(i) != find(j) && adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (a == -1)
        {
            break;
        }
        printf("%d->%d=%d\n", a, b, min);
        totalcost += min;
        unionSet(a, b);
        edgesUsed++;
        adj[a][b] = adj[b][a] = INT_MAX;
    }
    printf("\nTotal cost = %d\n", totalcost);
    return totalcost;
}

int main()
{

    printf("enter the no of vertises");
    scanf("%d", &n);

    printf("enter the weights to the adj matrix ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 0)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    kruskal();

    return 0;
}