// Name   : Addition of Two Polynomials Using Linked List
// Aim    : To add two polynomials represented as linked lists
// Author : Shanu S
// Date   : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

// Function Prototypes
struct node *insertTerm(struct node *head, int coeff, int exp);
struct node *readPolynomial();
void appendTerm(struct node **head, struct node **tail, int coeff, int exp);
struct node *addPolynomials(struct node *p1, struct node *p2);
void display(struct node *head);

int main()
{
    struct node *poly1, *poly2, *sum;

    printf("Enter first polynomial\n");
    poly1 = readPolynomial();

    printf("\nEnter second polynomial\n");
    poly2 = readPolynomial();

    sum = addPolynomials(poly1, poly2);

    printf("\nFirst polynomial  : ");
    display(poly1);

    printf("Second polynomial : ");
    display(poly2);

    printf("Sum               : ");
    display(sum);

    return 0;
}

struct node *insertTerm(struct node *head, int coeff, int exp)
{
    struct node *newnode, *temp, *prev = NULL;

    // A term with zero coefficient is not stored
    if(coeff == 0)
        return head;

    temp = head;

    // Find the position so that exponents stay in descending order
    while(temp != NULL && temp->exp > exp)
    {
        prev = temp;
        temp = temp->next;
    }

    // Same exponent already present: combine the coefficients
    if(temp != NULL && temp->exp == exp)
    {
        temp->coeff = temp->coeff + coeff;

        // Remove the term if the coefficient becomes zero
        if(temp->coeff == 0)
        {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
        }

        return head;
    }

    // Create a new node and insert it at the correct position
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = temp;

    if(prev == NULL)
        head = newnode;
    else
        prev->next = newnode;

    return head;
}

struct node *readPolynomial()
{
    struct node *head = NULL;
    int n, i, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter coefficient and exponent of term %d: ", i);
        scanf("%d %d", &coeff, &exp);

        head = insertTerm(head, coeff, exp);
    }

    return head;
}

void appendTerm(struct node **head, struct node **tail, int coeff, int exp)
{
    struct node *newnode;

    // Create a new term and add it at the end of the result list
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

struct node *addPolynomials(struct node *p1, struct node *p2)
{
    struct node *result = NULL, *tail = NULL;
    int sum;

    // Compare the exponents of both polynomials
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp > p2->exp)
        {
            appendTerm(&result, &tail, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if(p1->exp < p2->exp)
        {
            appendTerm(&result, &tail, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            // Same exponent: add the coefficients
            sum = p1->coeff + p2->coeff;

            if(sum != 0)
                appendTerm(&result, &tail, sum, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Copy the remaining terms of the first polynomial
    while(p1 != NULL)
    {
        appendTerm(&result, &tail, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Copy the remaining terms of the second polynomial
    while(p2 != NULL)
    {
        appendTerm(&result, &tail, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(struct node *head)
{
    struct node *temp = head;

    // An empty list represents the zero polynomial
    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    while(temp != NULL)
    {
        // Print the sign of the term
        if(temp != head)
        {
            if(temp->coeff < 0)
                printf(" - ");
            else
                printf(" + ");
        }
        else if(temp->coeff < 0)
        {
            printf("-");
        }

        // Print the coefficient
        printf("%d", abs(temp->coeff));

        // Print the variable part
        if(temp->exp > 1)
            printf("x^%d", temp->exp);
        else if(temp->exp == 1)
            printf("x");

        temp = temp->next;
    }

    printf("\n");
}

