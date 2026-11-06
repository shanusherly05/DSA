// Name : Queue Using Linked List
// Aim : To implement enqueue, dequeue, peek and display operations on a queue using a linked list
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Function Prototypes
// Inserts a new node at the rear of the queue
void enqueue(int data);
// Removes the node at the front of the queue
void dequeue();
// Displays the front element without removing it
void peek();
// Displays all the elements from front to rear
void display();

int main()
{
    int choice, data;

    while(1)
    {
        printf("\n--- Queue Using Linked List ---");
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
                enqueue(data);
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

void enqueue(int data)
{
    struct node *newnode;

    // Create a new node
    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Queue Overflow (memory not available).\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if(front == NULL)
    {
        // First element is both front and rear
        front = newnode;
        rear = newnode;
    }
    else
    {
        // Insert the new node at the rear
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element enqueued successfully.\n");
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow. Queue is empty.\n");
        return;
    }

    // Remove the node at the front
    temp = front;
    front = front->next;

    // If the queue becomes empty, rear must also be reset
    if(front == NULL)
        rear = NULL;

    printf("Dequeued element: %d\n", temp->data);

    free(temp);
}

void peek()
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    // Display the front element without removing it
    printf("Front element: %d\n", front->data);
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;

    printf("Queue (front to rear): ");

    // Traverse from the front node to the rear node
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
