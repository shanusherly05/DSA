// Name : Matching Brackets Using Stack (Array)
// Aim : To check whether brackets in an expression are properly matched
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>
#include <string.h>

#define MAX 100

// Function Prototypes
void push(char ch);
char pop();
int isMatching(char open, char close);
int isBalanced(char exp[]);

char stack[MAX];
int top = -1;

int main()
{
    char exp[MAX];

    printf("Enter expression: ");
    fgets(exp, MAX, stdin);

    if(isBalanced(exp))
        printf("Brackets are balanced.\n");
    else
        printf("Brackets are not balanced.\n");

    return 0;
}

void push(char ch)
{
    // Push the opening bracket into the stack
    if(top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    // Remove and return the top bracket
    if(top == -1)
        return '\0';

    return stack[top--];
}

int isMatching(char open, char close)
{
    // Check whether the opening and closing brackets form a valid pair
    if(open == '(' && close == ')')
        return 1;
    if(open == '[' && close == ']')
        return 1;
    if(open == '{' && close == '}')
        return 1;

    return 0;
}

int isBalanced(char exp[])
{
    int i;
    char ch, open;

    top = -1;

    for(i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        // Push every opening bracket
        if(ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        // Check every closing bracket with the top opening bracket
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if(top == -1)
                return 0;

            open = pop();

            if(!isMatching(open, ch))
                return 0;
        }
    }

    // Stack must be empty after checking the complete expression
    return top == -1;
}
