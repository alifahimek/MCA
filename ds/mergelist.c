#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *constructnode(int value)
{
    struct node *list1 = (struct node *)malloc(sizeof(struct node));

    list1->data = value;
    list1->next = NULL;
    return list1;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}
struct node *merged(struct node *list1, struct node *list2)
{
    struct node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

int main()
{
    struct node *new = constructnode(20);
    new->next = constructnode(30);
    new->next->next = constructnode(23);
    new->next->next->next = constructnode(50);

    struct node *new2 = constructnode(32);
    new2->next = constructnode(12);
    new2->next->next = constructnode(10);
    display(new);

    struct node *mergedlist = merged(new, new2);

    // struct node *head = NULL;
    display(new2);
    display(mergedlist);
}