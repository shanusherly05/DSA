// Name : Selection Sort
// Aim : To sort a list of numbers in ascending order using selection sort
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
// Sorts the array in ascending order using selection sort (prints every pass)
void selectionSort(int a[], int n);
// Displays all the elements of the array
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n = 0, i, choice;

    while(1)
    {
        printf("\n--- Selection Sort ---");
        printf("\n1. Enter Elements");
        printf("\n2. Display Array");
        printf("\n3. Sort the Array");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                if(n <= 0 || n > MAX)
                {
                    printf("Invalid number of elements.\n");
                    n = 0;
                    break;
                }

                printf("Enter %d elements: ", n);

                for(i = 0; i < n; i++)
                    scanf("%d", &a[i]);
                break;

            case 2:
                if(n == 0)
                    printf("Array is empty. Enter the elements first.\n");
                else
                {
                    printf("Array: ");
                    display(a, n);
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Array is empty. Enter the elements first.\n");
                    break;
                }

                printf("\nOriginal array: ");
                display(a, n);

                selectionSort(a, n);

                printf("\nSorted array: ");
                display(a, n);
                break;
            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        // Assume the first unsorted element is the smallest
        min = i;

        // Find the smallest element in the unsorted part
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        // Swap the smallest element with the first unsorted element
        if(min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

        printf("Pass %d: ", i + 1);
        display(a, n);
    }
}

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}
