// #include <stdio.h>
// #define MAX 10

// int stack[MAX];
// int top = -1;
// void push()
// {
//     if (top == MAX - 1)
//     {
//         printf("over");
//     }
//     else
//     {
//         int value;
//         printf("Enter value to push: ");
//         scanf("%d", &value);
//         stack[++top] = value;
//     }
// }

// void pop()
// {
//     if (top == -1)
//     {
//         printf("empt");
//     }
//     else
//     {
//         stack[top--];
//     }
// }

// void display()
// {
//     if (top == -1)
//     {
//         printf("empt");
//     }
//     else
//     {
//         for (int i = 0; i <= top; i++)
//         {
//             printf("stack is %d\n", stack[i]);
//         }
//     }
// }

// int main()
// {
//     int choice;
//     while (1)
//     {
//         printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             push();
//             break;
//         case 2:
//             pop();
//             break;
//         case 3:
//             display();
//             break;
//         default:
//             printf("Invalid choice\n");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX];

int top=-1;

void push(int value){
 if (top==MAX-1)
 {
    printf("Stack overflow\n");
 }
 else
 {
    stack[++top] = value;
 }
}

void pop(){
    if (top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        top--;
        printf("deleted.");
    }
}

void display(){
    if (top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}