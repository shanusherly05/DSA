// Name   : Stack Using Array
// Aim    : To implement stack operations using array
// Author : Shanu S
// Date   : 30/08/26

#include <stdio.h>

void push();
void pop();
void display();

int stack[100], top = -1, n;

int main()
{
    int ch;
    printf("Enter the size of stack: ");
    scanf("%d", &n);

    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice");
        }
    }
}

void push()
{
    int data;

    // Check whether the stack is full
    if(top == n - 1)
    {
        printf("Stack Overflow");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    // Increase top and insert the element
    top++;
    stack[top] = data;

    printf("Element pushed");
}

void pop()
{
    // Check whether the stack is empty
    if(top == -1)
    {
        printf("Stack Underflow");
        return;
    }

    // Delete the top element and decrease top
    printf("Popped element = %d", stack[top]);
    top--;
}

void display()
{
    int i;

    // Check whether the stack is empty
    if(top == -1)
    {
        printf("Stack is empty");
        return;
    }

    printf("Stack: ");

    // Display elements from top to bottom
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}