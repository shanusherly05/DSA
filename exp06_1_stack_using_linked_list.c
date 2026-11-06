// Name : Stack Using Linked List
// Aim : To implement push, pop, peek and display operations on a stack using a linked list
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Function Prototypes
// Inserts a new node at the top of the stack
void push(int data);
// Removes the top node of the stack
void pop();
// Displays the top element without removing it
void peek();
// Displays all the elements from top to bottom
void display();

int main()
{
    int choice, data;

    while(1)
    {
        printf("\n--- Stack Using Linked List ---");
        printf("\n1. Push");
        printf("\n2. Pop");
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
                push(data);
                break;

            case 2:
                pop();
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

void push(int data)
{
    struct node *newnode;

    // Create a new node
    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Stack Overflow (memory not available).\n");
        return;
    }

    newnode->data = data;

    // Insert the new node at the top
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack Underflow. Stack is empty.\n");
        return;
    }

    // Remove the top node
    temp = top;
    top = top->next;

    printf("Popped element: %d\n", temp->data);

    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    // Display the top element without removing it
    printf("Top element: %d\n", top->data);
}

void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;

    printf("Stack (top to bottom): ");

    // Traverse from the top node to the bottom node
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
