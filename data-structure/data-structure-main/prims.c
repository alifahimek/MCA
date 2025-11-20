#include <stdio.h>
#include <limits.h>
#define MAX 100

void prims(int adj[MAX][MAX], int n)
{
    int visited[MAX] = {0};
    int totalcost = 0;
    int no_ofEdges = 0;

    visited[0] = 1;
    while (no_ofEdges != n - 1)
    {
        int a = 0;
        int b = 0;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && adj[i][j] && adj[i][j] < minimum)
                    {
                        minimum = adj[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("%d->%d\t%d\n", a + 1, b + 1, adj[a][b]);

        visited[b] = 1;
        totalcost = totalcost + adj[a][b];

        no_ofEdges++;
    }
    printf("total minimum cost = %d", totalcost);
}

int main()
{
    int adj[MAX][MAX];
    int n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix if there is connection enter wight else 0:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("adj[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

    // printf("\nAdjacency Matrix:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         printf("%d ", adj[i][j]);
    //     printf("\n");
    // }

    // printf("Enter the starting vertex: ");
    // scanf("%d", &start);

    // if (start < 0 || start >= n)
    // {
    //     printf("Invalid vertex!\n");
    // }
    // else
    // {
    //
    // }
    prims(adj, n);
    return 0;
}
