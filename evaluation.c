// Name : Evaluation of Infix Expression Using Stacks
// Aim : To evaluate an infix expression using an operand stack and an operator stack
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int valStack[MAX];
int valTop = -1;

char opStack[MAX];
int opTop = -1;

char *errorMsg = NULL;

// Function Prototypes
void pushVal(int data);
int popVal();
void pushOp(char ch);
char popOp();
char peekOp();
int precedence(char op);
void applyOp();
int evaluate(char exp[]);

int main()
{
    char exp[MAX];
    int result;

    printf("Enter infix expression: ");
    fgets(exp, MAX, stdin);

    result = evaluate(exp);

    if(errorMsg != NULL)
        printf("Error: %s\n", errorMsg);
    else
        printf("Result = %d\n", result);

    return 0;
}

void pushVal(int data)
{
    // Push an operand into the operand stack
    if(valTop == MAX - 1)
    {
        errorMsg = "Operand stack overflow";
        return;
    }

    valStack[++valTop] = data;
}

int popVal()
{
    // Remove and return the top operand
    return valStack[valTop--];
}

void pushOp(char ch)
{
    // Push an operator or bracket into the operator stack
    if(opTop == MAX - 1)
    {
        errorMsg = "Operator stack overflow";
        return;
    }

    opStack[++opTop] = ch;
}

char popOp()
{
    // Remove and return the top operator
    return opStack[opTop--];
}

char peekOp()
{
    // Return the top operator without removing it
    return opStack[opTop];
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

void applyOp()
{
    int a, b, result = 1, i;
    char op;

    // Two operands and one operator are required
    if(valTop < 1 || opTop == -1)
    {
        errorMsg = "Invalid expression";
        return;
    }

    op = popOp();
    b = popVal();
    a = popVal();

    switch(op)
    {
        case '+':
            result = a + b;
            break;

        case '-':
            result = a - b;
            break;

        case '*':
            result = a * b;
            break;

        case '/':
            if(b == 0)
            {
                errorMsg = "Division by zero";
                return;
            }
            result = a / b;
            break;

        case '%':
            if(b == 0)
            {
                errorMsg = "Division by zero";
                return;
            }
            result = a % b;
            break;

        case '^':
            if(b < 0)
            {
                errorMsg = "Negative exponent is not supported";
                return;
            }
            for(i = 1; i <= b; i++)
                result = result * a;
            break;

        default:
            errorMsg = "Invalid operator";
            return;
    }

    pushVal(result);
}

int evaluate(char exp[])
{
    int i = 0, num;
    char ch;
    char prev = 's'; // s = start, n = number, o = operator, ( = open bracket

    valTop = -1;
    opTop = -1;
    errorMsg = NULL;

    while(exp[i] != '\0' && errorMsg == NULL)
    {
        ch = exp[i];

        // Skip spaces and the newline from fgets
        if(ch == ' ' || ch == '\n' || ch == '\t')
        {
            i++;
            continue;
        }

        // Read a complete multi-digit number
        if(isdigit(ch))
        {
            num = 0;

            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            pushVal(num);
            prev = 'n';
            continue;
        }

        if(ch == '(')
        {
            pushOp(ch);
            prev = '(';
        }
        else if(ch == ')')
        {
            // Evaluate everything until the matching opening bracket
            while(opTop != -1 && peekOp() != '(' && errorMsg == NULL)
                applyOp();

            if(errorMsg == NULL)
            {
                if(opTop == -1)
                    errorMsg = "Mismatched brackets";
                else
                    popOp();
            }

            prev = 'n';
        }
        else if(ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '%' || ch == '^')
        {
            // A minus sign at the start, after '(' or after an operator is unary
            if(ch == '-' && (prev == 's' || prev == '(' || prev == 'o'))
                pushVal(0);

            // Apply operators of higher or equal precedence first
            // '^' is right associative, so equal precedence is not applied for it
            while(opTop != -1 && peekOp() != '(' && errorMsg == NULL &&
                  (precedence(peekOp()) > precedence(ch) ||
                  (precedence(peekOp()) == precedence(ch) && ch != '^')))
            {
                applyOp();
            }

            pushOp(ch);
            prev = 'o';
        }
        else
        {
            errorMsg = "Invalid character in expression";
        }

        i++;
    }

    // Apply all remaining operators
    while(opTop != -1 && errorMsg == NULL)
    {
        if(peekOp() == '(')
            errorMsg = "Mismatched brackets";
        else
            applyOp();
    }

    // Exactly one value must remain in the operand stack
    if(errorMsg == NULL && valTop != 0)
        errorMsg = "Invalid expression";

    if(errorMsg != NULL)
        return 0;

    return popVal();
}


