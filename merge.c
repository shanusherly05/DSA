// Name : Merge Sort
// Aim : To sort a list of numbers in ascending order using merge sort
// Author : Shanu S
// Date : 25/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
// Recursively divides the array into halves and sorts them
void mergeSort(int a[], int low, int high);
// Merges two sorted halves a[low..mid] and a[mid+1..high] into one sorted part
void merge(int a[], int low, int mid, int high);
// Displays all the elements of the array
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n = 0, i, choice;

    while(1)
    {
        printf("\n--- Merge Sort ---");
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

                mergeSort(a, 0, n - 1);

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

void mergeSort(int a[], int low, int high)
{
    int mid;

    // A single element is already sorted
    if(low < high)
    {
        mid = (low + high) / 2;

        // Sort the left half and the right half
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // Merge the two sorted halves
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;

    // Copy the smaller element of the two halves into the temporary array
    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Copy the remaining elements of the left half
    while(i <= mid)
        temp[k++] = a[i++];

    // Copy the remaining elements of the right half
    while(j <= high)
        temp[k++] = a[j++];

    // Copy the merged elements back into the original array
    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];

    printf("Merged [%d to %d]: ", low, high);

    for(i = low; i <= high; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}
