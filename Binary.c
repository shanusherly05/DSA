// Name of program: Binary Search
// Aim: Binary search of an array
// Author: Shanu S
// Date: 27/07/2026

#include <stdio.h>

int binarysearch(int arr[], int n, int key);

int main() {
    int n, key, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    pos = binarysearch(arr, n, key);
    if(pos == -1) {
        printf("Element not found\n");
    } else {
            printf("Element found at position %d\n", pos + 1);
    }
    return 0;
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

