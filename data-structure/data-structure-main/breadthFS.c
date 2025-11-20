#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Function to enqueue
void enqueue(int n)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = n;
    }
}

// Function to dequeue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return val;
}

// BFS function
void BFS(int adj[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS -> ");
    while (front != -1)
    {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
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
        BFS(adj, n, start);
    }

    return 0;
}
