// Name of programme: Stack
// Aim: To implement push, pop, peek, display and size operations on a stack using an array
// Author: Shanu S
// Date: 06-07-26

#include <stdio.h>
#define max 100

int stack[max];
int top = -1;

// Function Prototypes
// Returns 1 if the stack is full, otherwise 0
int isFull();
// Returns 1 if the stack is empty, otherwise 0
int isEmpty();
// Inserts a value at the top of the stack (overflow check included)
void push(int value);
// Removes and returns the top value of the stack (underflow check included)
int pop();
// Returns the top value of the stack without removing it
int peek();
// Returns the number of elements present in the stack
int size();
// Displays all the stack elements from top to bottom
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Array ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Size");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                if (isEmpty())
                    printf("Stack underflow\n");
                else
                    printf("Popped element: %d\n", pop());
                break;

            case 3:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Top element (peek): %d\n", peek());
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Stack size: %d\n", size());
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == max - 1);
}
void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int size() {
    return top + 1;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
