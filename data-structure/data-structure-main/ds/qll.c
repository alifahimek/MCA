#include <stdio.h>
#include <stdlib.h>

struct q {
    int data;
    struct q *next;
};

struct q *constructnode(int value) {
    struct q *newnode = (struct q *)malloc(sizeof(struct q));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void deletebgn(struct q **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct q *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void display(struct q *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct q *temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct q *head = constructnode(30);
    head->next = constructnode(20);
    head->next->next = constructnode(10);

    printf("Before deletion:\n");
    display(head);

    deletebgn(&head);

    printf("After deleting first node:\n");
    display(head);

    return 0;
}
