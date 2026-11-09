
// Name : Quick Sort
// Aim : To sort a list of numbers in ascending order using quick sort
// Author : Shanu S
// Date : 25/10/26

#include <stdio.h>
#define MAX 100

// Function Prototypes
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n = 0, i, choice;

    while(1)
    {
        printf("\n--- Quick Sort ---");
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

                quickSort(a, 0, n - 1);

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

// Quick Sort Function
void quickSort(int a[], int low, int high)
{
    int p, i;

    if(low < high)
    {
        p = partition(a, low, high);

        printf("Pivot %d placed at index %d: ", a[p], p);

        for(i = low; i <= high; i++)
            printf("%d ", a[i]);

        printf("\n");

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Partition Function (First Element as Pivot)
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low + 1;
    int end = high;
    int temp;

    while(start <= end)
    {
        while(start <= high && a[start] <= pivot)
            start++;

        while(a[end] > pivot)
            end--;

        if(start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    temp = a[low];
    a[low] = a[end];
    a[end] = temp;

    return end;
}

// Display Function
void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}
