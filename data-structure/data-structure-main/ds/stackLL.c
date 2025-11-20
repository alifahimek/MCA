#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return -1; 
    }
    struct node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}


int peek(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}


void display(struct node *top)
{
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *stack = NULL; 

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    printf("Popped: %d\n", pop(&stack));
    display(stack);

    printf("Top element: %d\n", peek(stack));

    return 0;
}
