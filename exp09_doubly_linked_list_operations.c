// Name : Doubly Linked List Operations
// Aim : To implement operations on doubly linked list
// Author : Shanu S
// Date : 06/09/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Function Prototypes
// Inserts a new node at the beginning of the list
void insertBeginning();
// Inserts a new node at the end of the list
void insertEnd();
// Inserts a new node at a given position
void insertPosition();
// Deletes the first node of the list
void deleteBeginning();
// Deletes the last node of the list
void deleteEnd();
// Deletes the node at a given position
void deletePosition();
// Displays the list from the first node to the last node
void displayForward();
// Displays the list from the last node to the first node
void displayBackward();

int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Display Forward");
        printf("\n8. Display Backward");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: return 0;
            default: printf("Invalid choice");
        }
    }
}

void insertBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;
    printf("Element inserted successfully");
}

void insertEnd()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        printf("Element inserted successfully");
        return;
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    printf("Element inserted successfully");
}

void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        insertBeginning();
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Invalid position");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("Element inserted successfully");
}

void deleteBeginning()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    printf("Deleted element = %d", temp->data);
    free(temp);
}
void deleteEnd()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    printf("Deleted element = %d", temp->data);
    free(temp);
}

void deletePosition()
{
    struct node *temp;
    int pos, i;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        deleteBeginning();
        return;
    }
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Invalid position");
        return;
    }
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    printf("Deleted element = %d", temp->data);
    free(temp);
}

void displayForward()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void displayBackward()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    printf("Backward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
}
