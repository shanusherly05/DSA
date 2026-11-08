// Name : Singly Linked List
// Aim : Implimentation of linked list
// Author :Shanu S
// Date :31/08/2026
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function Prototypes
// Inserts a new node at the beginning of the list
void insertBeginning();
// Inserts a new node at the end of the list
void insertEnd();
// Inserts a new node at a given position
void insertPos();
// Deletes the first node of the list
void DeleteBeginning();
// Deletes the last node of the list
void DeleteEnd();
// Deletes the node at a given position
void Deleteposition();
// Searches for a value and replaces it with a new value
void searchAndUpdate();
// Displays all the nodes of the list
void display();

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Insert at postion");
        printf("\n4.Delete at Beginning");
        printf("\n5.Delete at End");
        printf("\n6.Delete at postion");
        printf("\n7.Search and Update");
        printf("\n8.Display");
        printf("\n9.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPos(); break;
            case 4: DeleteBeginning(); break;
            case 5: DeleteEnd(); break;
            case 6: Deleteposition(); break;
            case 7: searchAndUpdate(); break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Invalid Choice");
        }
    }
}

void insertBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List Empty");
        return;
    }
    temp = head;
    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertPos()
{
    struct node *newnode, *temp;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
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
    temp->next = newnode;
}

void DeleteBeginning()
{ struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element = %d", temp->data);
    free(temp);
}

void DeleteEnd()
{ struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    if(head->next == NULL)
    {
        printf("Deleted element = %d", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element = %d", temp->data);
    free(temp);
}

void Deleteposition()
{ struct node *temp, *prev;
    int pos,i;
    if(head == NULL)
    {printf("List is empty");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos < 1)
    { printf("Invalid position");
        return;
    }
    if(pos == 1)
    { temp = head;
        head = head->next;
        printf("Deleted elements = %d",temp->data);
        free(temp);
        return;
    }
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++)
    {prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    { printf("Invalid position");
        return;
    }
    prev->next = temp->next;
    printf("Deleted elements = %d",temp->data);
    free(temp);
}

void searchAndUpdate()
{ struct node *temp;
    int search,newdata;
    printf("Enter element to search: ");
    scanf("%d",&search);
    temp = head;
    while (temp != NULL)
    { if (temp->data == search)
        { printf("Element found\n");
            printf("Enter new data: ");
            scanf("%d",&newdata);
            temp->data = newdata;
            printf("modified");
            return;
        }
        temp = temp->next;
    }
    printf("element not found");
}
