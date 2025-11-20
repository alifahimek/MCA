#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int queue[MAX];
int rear = -1, front = -1;

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue is full!\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

int empty()
{
    return (front == -1 || front > rear);
}

void topologicalsort(int adj[MAX][MAX], int n)
{
    int indegry[MAX] = {0};
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                indegry[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegry[i] == 0)
        {
            enqueue(i);
        }
    }

    while (!empty())
    {
        int current = dequeue();
        printf("%d\t", current);
        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1)
            {
                indegry[i]--;
                if (indegry[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
        count++;
    }
    if (count != n)
        printf("Graph has cycle! Topological sort not possible!\n");
    else
        printf("\n");
}

int main()
{
    int adj[MAX][MAX];
    int n;

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
    topologicalsort(adj, n);
}
