

#include <stdio.h>

#define MAX 100

// Name   : Linear Search
// Aim    : To implement Linear Search using arrays
// Author : Shanu
// Date   : 25/07/2025

int linearSearch(int arr[], int n, int key);

int main()
{
    int arr[MAX], n, i, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if(result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at position %d (Index %d).\n", result + 1, result);

    return 0;
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
