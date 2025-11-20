

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(struct Node **head, struct Node *del)
{
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}
void printListForward(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtBeginning(&head, 2);

    printf("Forward: ");
    printListForward(head);

    deleteNode(&head, head->next);

    printf("After deletion:\nForward: ");
    printListForward(head);

    return 0;
}
