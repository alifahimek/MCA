#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
       
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(50);
    enqueue(30);
    display();

   
    display();

    enqueue(40);
    enqueue(50);
    enqueue(30);
    display();

    return 0;
}
