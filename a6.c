// Name : Multilevel Telephone Directory Using Linked List
// Aim : To implement a dynamic telephone directory using sorted index nodes and contact sub-lists
// Author : Shanu S
// Date : 04/10/26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_SIZE 50
#define PHONE_SIZE 20
#define EMAIL_SIZE 60

struct contact
{
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    struct contact *next;
};

struct indexNode
{
    char letter;
    struct contact *contacts;
    struct indexNode *next;
};

struct indexNode *head = NULL;

// Function Prototypes
struct indexNode *findIndex(char letter);
struct indexNode *createIndex(char letter);
struct contact *createContact(char name[], char phone[], char email[]);
int phoneExists(char phone[]);
void insertContact(char name[], char phone[], char email[]);
void deleteContact(char name[]);
void searchContact(char prefix[]);
void displayDirectory();

int main()
{
    int choice;
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    char prefix[NAME_SIZE];

    while(1)
    {
        printf("\n1. Insert Contact");
        printf("\n2. Delete Contact");
        printf("\n3. Search Contact");
        printf("\n4. Display Directory");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter phone number: ");
                fgets(phone, PHONE_SIZE, stdin);
                phone[strcspn(phone, "\n")] = '\0';

                printf("Enter email: ");
                fgets(email, EMAIL_SIZE, stdin);
                email[strcspn(email, "\n")] = '\0';

                insertContact(name, phone, email);
                break;

            case 2:
                printf("Enter name to delete: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';

                deleteContact(name);
                break;

            case 3:
                printf("Enter name prefix to search: ");
                fgets(prefix, NAME_SIZE, stdin);
                prefix[strcspn(prefix, "\n")] = '\0';

                searchContact(prefix);
                break;

            case 4:
                displayDirectory();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

struct indexNode *findIndex(char letter)
{
    struct indexNode *temp = head;

    // Traverse the sorted index list to find the required letter
    while(temp != NULL && temp->letter < letter)
        temp = temp->next;

    if(temp != NULL && temp->letter == letter)
        return temp;

    return NULL;
}

struct indexNode *createIndex(char letter)
{
    struct indexNode *newnode;
    struct indexNode *temp;

    // Create a new index node for the starting letter
    newnode = (struct indexNode *)malloc(sizeof(struct indexNode));

    newnode->letter = letter;
    newnode->contacts = NULL;
    newnode->next = NULL;

    // Insert the index node at the beginning when required
    if(head == NULL || letter < head->letter)
    {
        newnode->next = head;
        head = newnode;
        return newnode;
    }

    temp = head;

    // Find the sorted position of the new index node
    while(temp->next != NULL && temp->next->letter < letter)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;

    return newnode;
}

struct contact *createContact(char name[], char phone[], char email[])
{
    struct contact *newnode;

    // Allocate memory for a new contact
    newnode = (struct contact *)malloc(sizeof(struct contact));

    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);
    strcpy(newnode->email, email);

    newnode->next = NULL;

    return newnode;
}

int phoneExists(char phone[])
{
    struct indexNode *index;
    struct contact *temp;

    // Check every contact list for the duplicate phone number
    index = head;

    while(index != NULL)
    {
        temp = index->contacts;

        while(temp != NULL)
        {
            if(strcmp(temp->phone, phone) == 0)
                return 1;

            temp = temp->next;
        }

        index = index->next;
    }

    return 0;
}

void insertContact(char name[], char phone[], char email[])
{
    struct indexNode *index;
    struct contact *newnode;
    struct contact *temp;
    char letter;

    if(strlen(name) == 0)
    {
        printf("Invalid name.\n");
        return;
    }

    // Convert the first character to uppercase for the index
    letter = toupper(name[0]);

    if(!isalpha(letter))
    {
        printf("Name must start with a letter.\n");
        return;
    }

    // Duplicate phone numbers are not allowed
    if(phoneExists(phone))
    {
        printf("Duplicate phone number is not allowed.\n");
        return;
    }

    // Find or create the appropriate letter index
    index = findIndex(letter);

    if(index == NULL)
        index = createIndex(letter);

    newnode = createContact(name, phone, email);

    // Insert the contact alphabetically by name
    if(index->contacts == NULL ||
       strcasecmp(name, index->contacts->name) < 0)
    {
        newnode->next = index->contacts;
        index->contacts = newnode;
    }
    else
    {
        temp = index->contacts;

        while(temp->next != NULL &&
              strcasecmp(temp->next->name, name) < 0)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Contact inserted successfully.\n");
}

void deleteContact(char name[])
{
    struct indexNode *index;
    struct indexNode *prevIndex = NULL;
    struct contact *temp;
    struct contact *prev = NULL;
    char letter;

    if(strlen(name) == 0)
    {
        printf("Invalid name.\n");
        return;
    }

    // Find the index node using the first letter of the name
    letter = toupper(name[0]);
    index = head;

    while(index != NULL && index->letter != letter)
    {
        prevIndex = index;
        index = index->next;
    }

    if(index == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    temp = index->contacts;

    // Search for the contact by name
    while(temp != NULL && strcasecmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    // Remove the contact from the sub-list
    if(prev == NULL)
        index->contacts = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    // Remove the index node if its contact list is now empty
    if(index->contacts == NULL)
    {
        if(prevIndex == NULL)
            head = index->next;
        else
            prevIndex->next = index->next;

        free(index);
    }

    printf("Contact deleted successfully.\n");
}

void searchContact(char prefix[])
{
    struct indexNode *index;
    struct contact *temp;
    char letter;
    int found = 0;

    if(strlen(prefix) == 0)
    {
        printf("Invalid search prefix.\n");
        return;
    }

    // Use the first character to select the required contact sub-list
    letter = toupper(prefix[0]);
    index = findIndex(letter);

    if(index == NULL)
    {
        printf("No matching contacts found.\n");
        return;
    }

    temp = index->contacts;

    printf("Matching contacts:\n");

    // Display contacts whose names start with the given prefix
    while(temp != NULL)
    {
        if(strncasecmp(temp->name, prefix, strlen(prefix)) == 0)
        {
            printf("Name : %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Email: %s\n\n", temp->email);

            found = 1;
        }

        temp = temp->next;
    }

    if(!found)
        printf("No matching contacts found.\n");
}

void displayDirectory()
{
    struct indexNode *index;
    struct contact *temp;

    // Traverse all alphabetically sorted index nodes
    index = head;

    if(index == NULL)
    {
        printf("Directory is empty.\n");
        return;
    }

    while(index != NULL)
    {
        printf("\n[%c]\n", index->letter);

        // Display all contacts under the current letter
        temp = index->contacts;

        while(temp != NULL)
        {
            printf("Name : %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Email: %s\n", temp->email);

            temp = temp->next;
        }

        index = index->next;
    }
}
