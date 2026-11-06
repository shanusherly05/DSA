// Name : Decimal to Binary Conversion Using Stack (Array)
// Aim : To convert a decimal number into binary using a stack
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>

#define MAX 100

// Function Prototypes
void push(int data);
int pop();
void decimalToBinary(int n);

int stack[MAX];
int top = -1;

int main()
{
    int n;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    decimalToBinary(n);

    return 0;
}

void push(int data)
{
    // Store the binary remainder in the stack
    if(top < MAX - 1)
        stack[++top] = data;
}

int pop()
{
    // Remove the most recently stored binary digit
    return stack[top--];
}

void decimalToBinary(int n)
{
    int remainder;

    top = -1;

    if(n == 0)
    {
        printf("Binary: 0\n");
        return;
    }

    // Repeatedly divide by 2 and store the remainders
    while(n > 0)
    {
        remainder = n % 2;
        push(remainder);
        n = n / 2;
    }

    printf("Binary: ");

    // Pop remainders in reverse order to get the binary number
    while(top != -1)
    {
        printf("%d", pop());
    }

    printf("\n");
}
