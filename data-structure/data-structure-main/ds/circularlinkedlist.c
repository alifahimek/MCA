#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL)
    {

        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}
void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}
int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Circular Linked List: ");
    traverse(head);

    return 0;
}
