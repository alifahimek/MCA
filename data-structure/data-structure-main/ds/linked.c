#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *constructnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    printf("data:%d\n", newnode->data);
    return newnode;
}
void insertatend(struct node **head, int value)
{
    struct node *newnode = constructnode(value);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insertinbtw(struct node **head, int value, int position)
{
    struct node *newnode = constructnode(value);
    if (*head == NULL || position == 0)
    {
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
void deleteNode(struct node **head, int position)
{
    if (*head == NULL)
        return;

    struct node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
        return;

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("empty");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    struct node *head = NULL;

    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    display(head);

    insertinbtw(&head, 25, 2);
    display(head);

    deleteNode(&head, 1);
    display(head);

    return 0;
}