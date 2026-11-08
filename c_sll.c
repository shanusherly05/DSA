// Name   : Circular Singly Linked List - All Operations
// Aim    : To implement creation, insertion, deletion, search, modify and display operations on a Circular SLL
// Author : Shanu S
// Date   : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function Prototypes
void create();
void insertBeginning();
void insertEnd();
void insertPosition();
void deleteBeginning();
void deleteEnd();
void deletePosition();
void search();
void modify();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Circular Singly Linked List ---");
        printf("\n1. Create");
        printf("\n2. Insert Beginning");
        printf("\n3. Insert End");
        printf("\n4. Insert Position");
        printf("\n5. Delete Beginning");
        printf("\n6. Delete End");
        printf("\n7. Delete Position");
        printf("\n8. Search");
        printf("\n9. Modify");
        printf("\n10. Display");
        printf("\n11. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insertBeginning();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                insertPosition();
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                deletePosition();
                break;

            case 8:
                search();
                break;

            case 9:
                modify();
                break;

            case 10:
                display();
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void create()
{
    int n, i, data;
    struct node *newnode, *last = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = NULL;

    for(i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        // Create a new node
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;

        if(head == NULL)
        {
            // First node becomes head
            head = newnode;
            newnode->next = head;
            last = newnode;
        }
        else
        {
            // Add the new node after the last node
            newnode->next = head;
            last->next = newnode;
            last = newnode;
        }
    }

    printf("Circular linked list created successfully.\n");
}

void insertBeginning()
{
    int data;
    struct node *newnode, *last;

    printf("Enter data: ");
    scanf("%d", &data);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        // First node points to itself
        head = newnode;
        newnode->next = head;
    }
    else
    {
        // Find the last node
        last = head;

        while(last->next != head)
            last = last->next;

        // Insert new node before head
        newnode->next = head;
        last->next = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

void insertEnd()
{
    int data;
    struct node *newnode, *last;

    printf("Enter data: ");
    scanf("%d", &data);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        // First node points to itself
        head = newnode;
        newnode->next = head;
    }
    else
    {
        // Find the last node
        last = head;

        while(last->next != head)
            last = last->next;

        // Insert the new node at the end
        last->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted at end.\n");
}

void insertPosition()
{
    int data, pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    // Position 1 is handled by insertBeginning(), which asks for the data
    if(pos == 1)
    {
        insertBeginning();
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    temp = head;

    // Move to the node before the required position
    for(i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if(i != pos - 1)
    {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    // Insert the new node between temp and temp->next
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

void deleteBeginning()
{
    struct node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(head->next == head)
    {
        // Only one node exists
        free(head);
        head = NULL;
    }
    else
    {
        // Find the last node
        last = head;

        while(last->next != head)
            last = last->next;

        // Move head to the next node
        temp = head;
        head = head->next;
        last->next = head;

        free(temp);
    }

    printf("First node deleted.\n");
}

void deleteEnd()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(head->next == head)
    {
        // Only one node exists
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Find the last node and its previous node
        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        // Make previous node point to head
        prev->next = head;

        free(temp);
    }

    printf("Last node deleted.\n");
}

void deletePosition()
{
    int pos, i;
    struct node *temp, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    // Find the node at the required position
    for(i = 1; i < pos && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(i != pos)
    {
        printf("Invalid position.\n");
        return;
    }

    // Remove temp from the circular list
    prev->next = temp->next;

    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

void search()
{
    int key, pos = 1, found = 0;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    // Traverse until we reach head again
    do
    {
        if(temp->data == key)
        {
            printf("Element found at position %d.\n", pos);
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;

    } while(temp != head);

    if(!found)
        printf("Element not found.\n");
}

void modify()
{
    int oldData, newData, found = 0;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to modify: ");
    scanf("%d", &oldData);

    printf("Enter new value: ");
    scanf("%d", &newData);

    temp = head;

    // Search for the element and modify it
    do
    {
        if(temp->data == oldData)
        {
            temp->data = newData;
            found = 1;
            break;
        }

        temp = temp->next;

    } while(temp != head);

    if(found)
        printf("Element modified successfully.\n");
    else
        printf("Element not found.\n");
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular SLL: ");

    // Display until the pointer reaches head again
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while(temp != head);

    printf("\n");
}
