#include <stdio.h>

#define MAX 100

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
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
        printf("\n3. Exit");

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

                printf("\nOriginal array: ");
                display(a, n);

                mergeSort(a, 0, n - 1);

                printf("\nSorted array: ");
                display(a, n);
                break;

            case 2:
                if(n == 0)
                    printf("Array is empty. Enter elements first.\n");
                else
                {
                    printf("Array: ");
                    display(a, n);
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

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