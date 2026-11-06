// Name : Insertion Sort
// Aim : To sort a list of numbers in ascending order using insertion sort
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
// Sorts the array in ascending order using insertion sort (prints every pass)
void insertionSort(int a[], int n);
// Displays all the elements of the array
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n = 0, i, choice;

    while(1)
    {
        printf("\n--- Insertion Sort ---");
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

                insertionSort(a, n);

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
void insertionSort(int a[], int n)
{
    int i, j, key;

    // The first element is already sorted, so start from the second element
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        // Shift larger elements one position to the right
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // Place the key in its correct position
        a[j + 1] = key;

        printf("Pass %d: ", i);
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
