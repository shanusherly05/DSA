// Name : Priority Queue ADT Using Linked List
// Aim : To implement all priority queue operations using a linked list
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

// Function Prototypes
void enqueue(int data, int priority);
void dequeue();
void peek();
void display();

int main()
{
    int choice, data, priority;

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter priority: ");
                scanf("%d", &priority);

                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void enqueue(int data, int priority)
{
    struct node *newnode;
    struct node *temp;

    // Create a new priority queue node
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    // Insert at the beginning if the queue is empty
    // or the new node has higher priority
    if(front == NULL || priority < front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        temp = front;

        // Find the correct sorted position
        while(temp->next != NULL &&
              temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Element enqueued successfully.\n");
}

void dequeue()
{
    struct node *temp;

    // Check whether the priority queue is empty
    if(front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    // Remove the first node because it has highest priority
    temp = front;
    front = front->next;

    printf("Dequeued element: %d\n", temp->data);

    free(temp);
}

void peek()
{
    // Display the highest-priority element without removing it
    if(front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Highest priority element: %d\n", front->data);
    printf("Priority: %d\n", front->priority);
}

void display()
{
    struct node *temp;

    // Traverse the queue from highest to lowest priority
    if(front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    temp = front;

    printf("Priority Queue:\n");

    while(temp != NULL)
    {
        printf("Data: %d Priority: %d\n",
               temp->data, temp->priority);

        temp = temp->next;
    }
}
