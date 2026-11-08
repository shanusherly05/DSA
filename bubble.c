// Name : Bubble Sort
// Aim : To sort a list of numbers in ascending order using bubble sort
// Author : Shanu S
// Date : 25/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
// Sorts the array in ascending order using bubble sort (prints every pass)
void bubbleSort(int a[], int n);
// Displays all the elements of the array
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n = 0, i, choice;

    while(1)
    {
        printf("\n--- Bubble Sort ---");
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

                bubbleSort(a, n);

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

void bubbleSort(int a[], int n)
{
    int i, j, temp, swapped;

    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;

        // Compare adjacent elements and swap them if they are in the wrong order
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        printf("Pass %d: ", i + 1);
        display(a, n);

        // No swap in a complete pass means the array is already sorted
        if(swapped == 0)
            break;
    }
}

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}
