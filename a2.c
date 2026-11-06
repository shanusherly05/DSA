// Name : Two Stacks Using a Single One-Dimensional Array
// Aim : To implement two stacks using one one-dimensional array
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
void push1(int data);
void push2(int data);
void pop1();
void pop2();
void peek1();
void peek2();
void display1();
void display2();

int stack[MAX];
int top1 = -1;
int top2 = MAX;

int main()
{
    int choice, data;

    while(1)
    {
        printf("\n1. Push Stack 1");
        printf("\n2. Pop Stack 1");
        printf("\n3. Peek Stack 1");
        printf("\n4. Display Stack 1");
        printf("\n5. Push Stack 2");
        printf("\n6. Pop Stack 2");
        printf("\n7. Peek Stack 2");
        printf("\n8. Display Stack 2");
        printf("\n9. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push1(data);
                break;

            case 2:
                pop1();
                break;

            case 3:
                peek1();
                break;

            case 4:
                display1();
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                push2(data);
                break;

            case 6:
                pop2();
                break;

            case 7:
                peek2();
                break;

            case 8:
                display2();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void push1(int data)
{
    // Stack 1 grows from the beginning toward the centre
    if(top1 + 1 == top2)
    {
        printf("Stack Overflow.\n");
        return;
    }

    stack[++top1] = data;
    printf("Element pushed into Stack 1.\n");
}

void push2(int data)
{
    // Stack 2 grows from the end toward the centre
    if(top1 + 1 == top2)
    {
        printf("Stack Overflow.\n");
        return;
    }

    stack[--top2] = data;
    printf("Element pushed into Stack 2.\n");
}

void pop1()
{
    // Remove the top element of Stack 1
    if(top1 == -1)
    {
        printf("Stack 1 is empty.\n");
        return;
    }

    printf("Popped element: %d\n", stack[top1--]);
}

void pop2()
{
    // Remove the top element of Stack 2
    if(top2 == MAX)
    {
        printf("Stack 2 is empty.\n");
        return;
    }

    printf("Popped element: %d\n", stack[top2++]);
}

void peek1()
{
    // Display the top element without removing it
    if(top1 == -1)
    {
        printf("Stack 1 is empty.\n");
        return;
    }

    printf("Top element of Stack 1: %d\n", stack[top1]);
}

void peek2()
{
    // Display the top element of Stack 2 without removing it
    if(top2 == MAX)
    {
        printf("Stack 2 is empty.\n");
        return;
    }

    printf("Top element of Stack 2: %d\n", stack[top2]);
}

void display1()
{
    int i;

    // Display Stack 1 from top to bottom
    if(top1 == -1)
    {
        printf("Stack 1 is empty.\n");
        return;
    }

    printf("Stack 1: ");

    for(i = top1; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

void display2()
{
    int i;

    // Display Stack 2 from top to bottom
    if(top2 == MAX)
    {
        printf("Stack 2 is empty.\n");
        return;
    }

    printf("Stack 2: ");

    for(i = top2; i < MAX; i++)
        printf("%d ", stack[i]);

    printf("\n");
}

