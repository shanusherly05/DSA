// Header files
#include <stdio.h>      // Provides printf(), fgets()
#include <ctype.h>     // Provides isdigit(), isspace()

// Stack declaration
char stack[100];        // Array used to implement the stack
int top = -1;           // Indicates the top position of stack
                        // top = -1 means stack is empty


// PUSH FUNCTION
// Inserts an operator or parenthesis into the stack
void push(char x)
{
    stack[++top] = x;   // First increment top, then insert x
}


// POP FUNCTION
// Removes and returns the top element from the stack
char pop()
{
    return stack[top--]; // Return top element, then decrement top
}


// PRECEDENCE FUNCTION
// Returns the priority of operators
int precedence(char x)
{
    if (x == '^')       // Highest precedence
        return 3;

    if (x == '*' || x == '/') // Multiplication and division
        return 2;

    if (x == '+' || x == '-') // Addition and subtraction
        return 1;

    return 0;           // Default precedence
}


// MAIN FUNCTION
int main()
{
    char infix[100], postfix[200];
    // infix[]   = Stores the input expression
    // postfix[] = Stores the converted postfix expression

    int i = 0, j = 0;
    // i = Index for reading infix expression
    // j = Index for writing postfix expression


    // Read the infix expression
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);


    // Process the expression character by character
    while (infix[i] != '\0' && infix[i] != '\n')
    {
        // CASE 1: Ignore spaces
        if (isspace(infix[i]))
        {
            i++;  // Move to the next character
        }


        // CASE 2: If the character is a digit
        else if (isdigit(infix[i]))
        {
            // Read all consecutive digits
            // This allows multiple-digit numbers such as 123, 4567

            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
                // Copy the digit into postfix
                // Increment both i and j
            }

            postfix[j++] = ' ';
            // Add space to separate complete operands
        }


        // CASE 3: If opening parenthesis is encountered
        else if (infix[i] == '(')
        {
            push(infix[i]);
            // Push '(' into the stack

            i++;  // Move to the next character
        }


        // CASE 4: If closing parenthesis is encountered
        else if (infix[i] == ')')
        {
            // Pop operators until '(' is found

            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
                // Remove operator from stack
                // Insert it into postfix expression

                postfix[j++] = ' ';
                // Add space after the operator
            }

            pop();
            // Remove '(' from the stack
            // Parentheses are not included in postfix

            i++;  // Move to the next character
        }


        // CASE 5: If the character is an operator
        else
        {
            // Compare precedence of stack operator
            // with the current infix operator

            while (top != -1 &&
                  (precedence(stack[top]) > precedence(infix[i]) ||
                  (precedence(stack[top]) == precedence(infix[i])
                  && infix[i] != '^')))
            {
                postfix[j++] = pop();
                // Pop higher-precedence operator
                // and insert it into postfix

                postfix[j++] = ' ';
                // Add separator
            }

            push(infix[i]);
            // Push current operator into stack

            i++;  // Move to the next character
        }
    }


    // After scanning the complete infix expression,
    // pop all remaining operators from the stack

    while (top != -1)
    {
        postfix[j++] = pop();
        // Remove remaining operator and add to postfix

        postfix[j++] = ' ';
        // Add space after operator
    }


    // Add null character to terminate the postfix string
    postfix[j] = '\0';


    // Display the final postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;  // End the program successfully
}
