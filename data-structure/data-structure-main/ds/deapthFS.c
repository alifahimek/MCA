#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int n)
{

    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = n;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        return stack[top--];
    }
}

void DFS(int adj[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};

    push(start);

    visited[start] = 1;

    printf("DFS->");

    while (top != -1)
    {
        int node = pop();

        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int adj[MAX][MAX];
    int n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (1 if connected, 0 if not):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("adj[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid vertex!\n");
    }
    else
    {
        DFS(adj, n, start);
    }

    return 0;
}
