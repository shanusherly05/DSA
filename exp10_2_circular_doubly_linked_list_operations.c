// Name : Circular Doubly Linked List - All Operations
// Aim : To implement creation, insertion, deletion, search, modify and display operations on a Circular DLL
// Author : Shanu S
// Date : 05/10/26

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
// Creates the circular list by reading the required number of nodes
void create();
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
// Searches for a value and displays its position
void search();
// Replaces an existing value with a new value
void modify();
// Displays the list from the first node to the last node
void displayForward();
// Displays the list from the last node to the first node
void displayBackward();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Circular Doubly Linked List ---");
        printf("\n1. Create");
        printf("\n2. Insert Beginning");
        printf("\n3. Insert End");
        printf("\n4. Insert Position");
        printf("\n5. Delete Beginning");
        printf("\n6. Delete End");
        printf("\n7. Delete Position");
        printf("\n8. Search");
        printf("\n9. Modify");
        printf("\n10. Display Forward");
        printf("\n11. Display Backward");
        printf("\n12. Exit");

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
                displayForward();
                break;

            case 11:
                displayBackward();
                break;

            case 12:
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
            // First node points to itself in both directions
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
            last = newnode;
        }
        else
        {
            // Insert the new node after the last node
            newnode->next = head;
            newnode->prev = last;
            last->next = newnode;
            head->prev = newnode;

            last = newnode;
        }
    }

    printf("Circular doubly linked list created successfully.\n");
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
        // First node points to itself in both directions
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        // Last node is head->prev
        last = head->prev;

        // Insert new node before head
        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

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
        newnode->prev = head;
    }
    else
    {
        // In a circular DLL, head->prev is the last node
        last = head->prev;

        // Insert new node between last and head
        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
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
    // Insert new node between temp and temp->next
    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

void deleteBeginning()
{
    struct node *last, *temp;

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
        // Get the last node
        last = head->prev;
        temp = head;

        // Move head to the next node
        head = head->next;

        last->next = head;
        head->prev = last;

        free(temp);
    }

    printf("First node deleted.\n");
}

void deleteEnd()
{
    struct node *last, *newLast;

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
        // Last node is head->prev
        last = head->prev;

        // New last node is previous node of last
        newLast = last->prev;

        newLast->next = head;
        head->prev = newLast;

        free(last);
    }

    printf("Last node deleted.\n");
}

void deletePosition()
{
    int pos, i;
    struct node *temp;

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

    // Move to the required node
    for(i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;
    if(i != pos)
    {
        printf("Invalid position.\n");
        return;
    }

    // Connect the previous and next nodes
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

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

    // Traverse forward until head is reached again
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

    // Search through the circular list and modify the element
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

void displayForward()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward: ");

    // Traverse using next pointers
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while(temp != head);

    printf("\n");
}

void displayBackward()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // Start from the last node
    temp = head->prev;

    printf("Backward: ");

    // Traverse using prev pointers
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;

    } while(temp != head->prev);

    printf("\n");
}
