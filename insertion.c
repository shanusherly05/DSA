// Name   : Insertion Sort
// Aim    : To sort a list of numbers in ascending order using insertion sort
// Author : Shanu S
// Date   : 05/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
void insertionSort(int a[], int n);
void display(int a[], int n);

int main()
{
    int a[MAX];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal array: ");
    display(a, n);

    insertionSort(a, n);

    printf("\nSorted array: ");
    display(a, n);

    return 0;
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
