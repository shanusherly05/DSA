#include <stdio.h>

#define MAX 100

// Name : Linear Search
// Aim : To implement Linear Search using arrays
// Author : Shanu
// Date : 25/07/2025

// Function Prototypes
// Searches the key in the array one by one; returns its index or -1 if not found
int linearSearch(int arr[], int n, int key);

int main()
{
    int arr[MAX], n = 0, i, key, result, choice;

    while(1)
    {
        printf("\n--- Linear Search ---");
        printf("\n1. Enter Array Elements");
        printf("\n2. Display Array");
        printf("\n3. Search an Element");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);

                if(n <= 0 || n > MAX)
                {
                    printf("Invalid number of elements.\n");
                    n = 0;
                    break;
                }

                printf("Enter elements:\n");
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if(n == 0)
                    printf("Array is empty. Enter the elements first.\n");
                else
                {
                    printf("Array: ");
                    for(i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Array is empty. Enter the elements first.\n");
                    break;
                }

                printf("Enter the element to search: ");
                scanf("%d", &key);

                result = linearSearch(arr, n, key);

                if(result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at position %d (Index %d).\n", result + 1, result);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

int linearSearch(int arr[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
