// Name   : Priority Queue using Array
// Aim    : To implement a priority queue using array
// Author : Shanu S
// Date   : 10/11/26

#include <stdio.h>

#define MAX 100

int que[MAX], pro[MAX];
int n = 0;

// Function Prototypes
void enqueue();
void dequeue();
void display();

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- PRIORITY QUEUE ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }
}

// Enqueue Operation
void enqueue()
{
    int item, p;

    if(n == MAX)
    {
        printf("\nPriority Queue is Full!");
        return;
    }

    printf("\nEnter element: ");
    scanf("%d", &item);

    printf("Enter priority: ");
    scanf("%d", &p);

    que[n] = item;
    pro[n] = p;

    n++;

    printf("\nElement inserted successfully!");
}

// Dequeue Operation
void dequeue()
{
    int pos = 0, i;

    if(n == 0)
    {
        printf("\nPriority Queue is Empty!");
        return;
    }

    for(i = 1; i < n; i++)
    {
        if(pro[i] < pro[pos])
        {
            pos = i;
        }
    }

    printf("\nDeleted element: %d", que[pos]);

    for(i = pos; i < n - 1; i++)
    {
        que[i] = que[i + 1];
        pro[i] = pro[i + 1];
    }

    n--;
}

// Display Operation
void display()
{
    int i;

    if(n == 0)
    {
        printf("\nPriority Queue is Empty!");
        return;
    }

    printf("\nElement\tPriority\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\n", que[i], pro[i]);
    }
}