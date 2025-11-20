#include <stdio.h>

int main()
{
    int arr[10];
    printf("Enter  elements of the array:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements in the array are:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
