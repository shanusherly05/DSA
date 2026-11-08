// Name   : Multiplication of Two Polynomials Using Linked List
// Aim    : To multiply two polynomials represented as linked lists
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
struct node *multiplyPolynomials(struct node *p1, struct node *p2);
void display(struct node *head);
void freeList(struct node *head);

int main()
{
    struct node *poly1, *poly2, *product;

    printf("Enter first polynomial\n");
    poly1 = readPolynomial();

    printf("\nEnter second polynomial\n");
    poly2 = readPolynomial();

    product = multiplyPolynomials(poly1, poly2);

    printf("\nFirst polynomial  : ");
    display(poly1);

    printf("Second polynomial : ");
    display(poly2);

    printf("Product           : ");
    display(product);

    freeList(poly1);
    freeList(poly2);
    freeList(product);

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

struct node *multiplyPolynomials(struct node *p1, struct node *p2)
{
    struct node *result = NULL;
    struct node *t1, *t2;

    // Multiply every term of the first polynomial with every term of the second
    for(t1 = p1; t1 != NULL; t1 = t1->next)
    {
        for(t2 = p2; t2 != NULL; t2 = t2->next)
        {
            // Coefficients are multiplied and exponents are added
            // insertTerm() combines terms with the same exponent
            result = insertTerm(result,
                                t1->coeff * t2->coeff,
                                t1->exp + t2->exp);
        }
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
