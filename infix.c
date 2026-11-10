#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;

    if (x == '*' || x == '/')
        return 2;

    if (x == '+' || x == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[100], postfix[200];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    while (infix[i] != '\0' && infix[i] != '\n')
    {
        if (isspace(infix[i]))
        {
            i++;
        }

        else if (isdigit(infix[i]))
        {
            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
            }

            postfix[j++] = ' ';
        }

        else if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }

        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }

            pop();
            i++;
        }

        else
        {
            while (top != -1 &&
                  (precedence(stack[top]) > precedence(infix[i]) ||
                  (precedence(stack[top]) == precedence(infix[i])
                  && infix[i] != '^')))
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }

            push(infix[i]);
            i++;
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}