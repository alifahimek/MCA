#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

int display();
void creation();
void deletion();

int main()
{

    while (1)
    {
        int choice;
        printf("Enter 0 to display, 1 to insert, 2 to delete, 5 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            display();
            break;
        case 1:
            creation();
            break;
        case 2:
            deletion();
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
}

struct node *insert(struct node *root, struct node *newnode)
{

    if (root == NULL)
    {
        root = newnode;
    }
    else if (root->data > newnode->data)
    {
        root->left = insert(root->left, newnode);
    }
    else
    {
        root->right = insert(root->right, newnode);
    }
    return root;
}

void creation()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(newnode));
    printf("element");
    scanf("%d", &newnode->data);

    newnode->left = newnode->right = NULL;
    root = insert(root, newnode);
    display();
}
struct node *FindMin(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *deleteNode(struct node *root, int vlaue)
{

    if (root == NULL)
    {
        printf("empty");
        return root;
    }

    struct node *temp;

    if (vlaue > root->data)
    {
        root->right = deleteNode(root->right, vlaue);
    }
    else if (vlaue < root->data)
    {
        root->left = deleteNode(root->left, vlaue);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
    }
    root->data = FindMin(root->right)->data;
    root->right = deleteNode(root->right, root->data);
}

void deletion()
{
    int value;
    printf("enter the value to delete:");
    scanf("%d", &value);
    root = deleteNode(root, value);
    display();
}

int preorder(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}
int postorder(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}

int inorder(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

int display()
{
    if (root == NULL)
    {
        printf("empty");
        return 1;
    }
    printf("preorder");
    preorder(root);
    printf("NULL\npostorder");
    postorder(root);
    printf("NULL\ninorder");
    inorder(root);
    printf("NULL\n");
    return 0;
}