// Name : Hash Table using Linear Probing
// Aim : To implement a hash table using linear probing for collision resolution
// Author : Shanu S
// Date : 06/11/26

#include <stdio.h>

#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index = hash(key);
    int start = index;

    while (table[index] != -1)
    {
        printf("Collision at index %d\n", index);

        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash Table Overflow!\n");
            return;
        }
    }

    table[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

void display(int table[])
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d : ", i);

        if (table[i] == -1)
            printf("EMPTY");
        else
            printf("%d", table[i]);

        printf("\n");
    }
}

int main()
{
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        insert(table, key);
    }

    display(table);

    return 0;
}
