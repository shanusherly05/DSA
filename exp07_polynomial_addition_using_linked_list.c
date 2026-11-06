// Name : Addition of Two Polynomials Using Linked List
// Aim : To add two polynomials represented as linked lists
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

// Function Prototypes
// Inserts a term in descending order of exponent (same exponents are combined)
struct node *insertTerm(struct node *head, int coeff, int exp);
// Reads the terms of a polynomial and returns it as a linked list
struct node *readPolynomial();
// Adds a term at the end of the result list
void appendTerm(struct node **head, struct node **tail, int coeff, int exp);
// Adds two polynomials and returns the sum as a new list
struct node *addPolynomials(struct node *p1, struct node *p2);
// Displays a polynomial in algebraic form
void display(struct node *head);
// Frees all the nodes of a polynomial list
void freeList(struct node *head);

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int choice;

    while(1)
    {
        printf("\n--- Polynomial Addition Using Linked List ---");
        printf("\n1. Enter First Polynomial");
        printf("\n2. Enter Second Polynomial");
        printf("\n3. Display Polynomials");
        printf("\n4. Add Polynomials");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                freeList(poly1);
                printf("Enter first polynomial\n");
                poly1 = readPolynomial();
                break;

            case 2:
                freeList(poly2);
                printf("Enter second polynomial\n");
                poly2 = readPolynomial();
                break;

            case 3:
                printf("First polynomial : ");
                display(poly1);

                printf("Second polynomial : ");
                display(poly2);
                break;

            case 4:
                if(poly1 == NULL || poly2 == NULL)
                {
                    printf("Enter both polynomials first.\n");
                    break;
                }

                freeList(sum);
                sum = addPolynomials(poly1, poly2);

                printf("First polynomial : ");
                display(poly1);

                printf("Second polynomial : ");
                display(poly2);

                printf("Sum : ");
                display(sum);
                break;

            case 5:
                freeList(poly1);
                freeList(poly2);
                freeList(sum);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
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

        if(exp < 0)
        {
            printf("Exponent cannot be negative. Enter the term again.\n");
            i--;
            continue;
        }

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

void freeList(struct node *head)
{
    struct node *temp;

    // Free every node of the list
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
