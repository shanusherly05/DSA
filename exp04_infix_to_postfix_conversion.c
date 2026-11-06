// Name : Infix to Postfix Conversion Using Stack
// Aim : To convert an infix expression into a postfix expression with a space between each token
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function Prototypes
// Pushes an operator or bracket into the stack
void push(char ch);
// Removes and returns the top element of the stack
char pop();
// Returns the top element of the stack without removing it
char peek();
// Returns the precedence value of an operator
int precedence(char op);
// Returns 1 if the character is an arithmetic operator
int isOperator(char ch);
// Converts the infix expression into postfix; returns 0 for an invalid expression
int infixToPostfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX];
    char postfix[2 * MAX];
    int choice;

    while(1)
    {
        printf("\n--- Infix to Postfix Conversion ---");
        printf("\n1. Convert Infix to Postfix");
        printf("\n2. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter infix expression: ");
                scanf(" %99[^\n]", infix);

                if(infixToPostfix(infix, postfix))
                    printf("Postfix expression: %s\n", postfix);
                else
                    printf("Invalid expression.\n");
                break;

            case 2:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void push(char ch)
{
    // Push an operator or bracket into the stack
    if(top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    // Remove and return the top element
    return stack[top--];
}

char peek()
{
    // Return the top element without removing it
    return stack[top];
}

int precedence(char op)
{
    // Higher number means higher precedence
    if(op == '^')
        return 3;
    if(op == '*' || op == '/' || op == '%')
        return 2;
    if(op == '+' || op == '-')
        return 1;

    return 0;
}

int isOperator(char ch)
{
    // Check whether the character is an arithmetic operator
    return (ch == '+' || ch == '-' || ch == '*' ||
    ch == '/' || ch == '%' || ch == '^');
}

int infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch;

    top = -1;

    while(infix[i] != '\0')
    {
        ch = infix[i];

        // Skip spaces and the newline from fgets
        if(ch == ' ' || ch == '\n' || ch == '\t')
        {
            i++;
            continue;
        }

        // Copy a complete multi-digit number and add a space after it
        if(isdigit(ch))
        {
            while(isdigit(infix[i]))
                postfix[j++] = infix[i++];

            postfix[j++] = ' ';
            continue;
        }

        // Copy a single-letter operand and add a space after it
        if(isalpha(ch))
        {
            postfix[j++] = ch;
            postfix[j++] = ' ';
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            // Pop operators until the opening bracket is found
            while(top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            // No opening bracket means the brackets are not matched
            if(top == -1)
                return 0;

            // Remove the opening bracket
            pop();
        }
        else if(isOperator(ch))
        {
            // Pop operators of higher or equal precedence first
            // '^' is right associative, so equal precedence is not popped for it
            while(top != -1 && peek() != '(' &&
            (precedence(peek()) > precedence(ch) ||
            (precedence(peek()) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }

            push(ch);
        }
        else
        {
            // Invalid character in the expression
            return 0;
        }

        i++;
    }

    // Pop all remaining operators from the stack
    while(top != -1)
    {
        // A remaining opening bracket means the brackets are not matched
        if(peek() == '(')
            return 0;

        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    // Remove the extra space at the end
    if(j > 0)
        j--;

    postfix[j] = '\0';

    return 1;
}
