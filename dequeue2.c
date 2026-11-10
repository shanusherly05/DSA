// Name   : Double Ended Queue
// Aim    : Implementation of Double Ended Queue using Circular Array
// Author : Shanu S
// Date   : 03/08/2026

#include <stdio.h>
#define MAX 5

// Function Prototypes
void insertfront();
void insertrear();
void deletefront();
void deleterear();
void display();

int queue[MAX];
int front = -1, rear = -1;

// Main Function
int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insertfront();
                break;

            case 2:
                insertrear();
                break;

            case 3:
                deletefront();
                break;

            case 4:
                deleterear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }
}

// Insert Front
void insertfront()
{
    int item;

    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nQueue Full!");
        return;
    }

    printf("\nEnter the element: ");
    scanf("%d", &item);

    if(front == -1)
        front = rear = 0;
    else
        front = (front - 1 + MAX) % MAX;

    queue[front] = item;
}

// Insert Rear
void insertrear()
{
    int item;

    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nQueue Full!");
        return;
    }

    printf("\nEnter the element: ");
    scanf("%d", &item);

    if(front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = item;
}

// Delete Front
void deletefront()
{
    if(front == -1)
    {
        printf("\nQueue Empty!");
        return;
    }

    printf("\nDeleted = %d", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

// Delete Rear
void deleterear()
{
    if(front == -1)
    {
        printf("\nQueue Empty!");
        return;
    }

    printf("\nDeleted = %d", queue[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

// Display
void display()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue Empty!");
        return;
    }

    printf("\nQueue:\n");

    i = front;

    while(1)
    {
        printf("%d\n", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}