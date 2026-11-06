// Name of program: Binary Search
// Aim: Binary search of an array
// Author: Shanu S
// Date: 27/07/2026

#include <stdio.h>

#define MAX 100
// Function Prototypes
// Searches the key in a sorted array by repeatedly halving the range; returns index or -1
int binarysearch(int arr[], int n, int key);

int main() {
    int n = 0, key, pos, choice, i, sorted;
    int arr[MAX];

    while(1) {
        printf("\n--- Binary Search ---");
        printf("\n1. Enter Sorted Array Elements");
        printf("\n2. Display Array");
        printf("\n3. Search an Element");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);

                if(n <= 0 || n > MAX) {
                    printf("Invalid number of elements.\n");
                    n = 0;
                    break;
                }

                printf("Enter the sorted array elements:\n");
                for(i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                // Binary search works only on an array sorted in ascending order
                sorted = 1;
                for(i = 0; i < n - 1; i++) {
                    if(arr[i] > arr[i + 1])
                        sorted = 0;
                }

                if(!sorted) {
                    printf("Array is not sorted. Enter the elements in ascending order.\n");
                    n = 0;
                }
                break;

            case 2:
                if(n == 0) {
                    printf("Array is empty. Enter the elements first.\n");
                } else {
                    printf("Array: ");
                    for(i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 3:
                if(n == 0) {
                    printf("Array is empty. Enter the elements first.\n");
                    break;
                }

                printf("Enter element to search: ");
                scanf("%d", &key);

                pos = binarysearch(arr, n, key);

                if(pos == -1) {
                    printf("Element not found\n");
                } else {
                    printf("Element found at position %d\n", pos + 1);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

int binarysearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
