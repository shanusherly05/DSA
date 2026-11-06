// Name : Queue Using Stacks (Linked List)
// Aim : To implement a normal queue using two stacks implemented with linked lists
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *stack1 = NULL;
struct node *stack2 = NULL;

// Function Prototypes
void push(struct node **top, int data);
int pop(struct node **top);
void printReverse(struct node *t);
void enqueue(int data);
void dequeue();
void peek();
void display();

int main()
{
    int choice, data;

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

void push(struct node **top, int data)
{
    struct node *newnode;

    // Create a new stack node
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;

    // Insert the new node at the top
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top)
{
    struct node *temp;
    int data;

    // Remove the top node from the stack
    temp = *top;
    data = temp->data;

    *top = temp->next;

    free(temp);

    return data;
}

void printReverse(struct node *t)
{
    // Print a stack from bottom to top using recursion
    if(t == NULL)
        return;

    printReverse(t->next);
    printf("%d ", t->data);
}

void enqueue(int data)
{
    // Insert new queue elements into Stack 1
    push(&stack1, data);

    printf("Element enqueued successfully.\n");
}

void dequeue()
{
    int data;

    if(stack1 == NULL && stack2 == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    // Transfer elements only when Stack 2 is empty
    if(stack2 == NULL)
    {
        while(stack1 != NULL)
        {
            data = pop(&stack1);
            push(&stack2, data);
        }
    }

    // Oldest element is now on top of Stack 2
    data = pop(&stack2);

    printf("Dequeued element: %d\n", data);
}

void peek()
{
    int data;

    if(stack1 == NULL && stack2 == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    // Move elements to Stack 2 if necessary
    if(stack2 == NULL)
    {
        while(stack1 != NULL)
        {
            data = pop(&stack1);
            push(&stack2, data);
        }
    }

    // Read the front element without deleting it
    printf("Front element: %d\n", stack2->data);
}

void display()
{
    struct node *temp;

    if(stack1 == NULL && stack2 == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    // Display Stack 2 from top to bottom (oldest elements first)
    temp = stack2;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Display Stack 1 from bottom to top (remaining elements in arrival order)
    printReverse(stack1);

    printf("\n");
}

