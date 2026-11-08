//*****
//Program name: DivisionChaining.c
//Aim: To implement hash table using division method with chaining
//Author: Shanu 
//Date: 28/10/2026
//*****

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *table[SIZE];

int hash(int key);
void insert(int key);
int search(int key);
void deleteKey(int key);
void display();

int main()
{
    int i, choice, key;

    for(i = 0; i < SIZE; i++)
        table[i] = NULL;

    do
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);

                if(search(key))
                    printf("Key found\n");
                else
                    printf("Key not found\n");
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

//Function name: hash
//Aim: To calculate hash address using division method
int hash(int key)
{
    return key % SIZE;
}

//Function name: insert
//Aim: To insert a key into the hash table using chaining
void insert(int key)
{
    int index = hash(key);
    struct node *temp, *p;

    if(search(key))
    {
        printf("Duplicate key\n");
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = key;
    temp->next = NULL;

    if(table[index] == NULL)
        table[index] = temp;
    else
    {
        p = table[index];

        while(p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    printf("Key inserted at index %d\n", index);
}

//Function name: search
//Aim: To search for a key in the hash table
int search(int key)
{
    int index = hash(key);
    struct node *p = table[index];

    while(p != NULL)
    {
        if(p->data == key)
            return 1;

        p = p->next;
    }

    return 0;
}

//Function name: deleteKey
//Aim: To delete a key from the hash table
void deleteKey(int key)
{
    int index = hash(key);
    struct node *p = table[index], *prev = NULL;

    while(p != NULL)
    {
        if(p->data == key)
        {
            if(prev == NULL)
                table[index] = p->next;
            else
                prev->next = p->next;

            free(p);
            printf("Key deleted\n");
            return;
        }

        prev = p;
        p = p->next;
    }

    printf("Key not found\n");
}

//Function name: display
//Aim: To display the hash table and its chains
void display()
{
    int i;
    struct node *p;

    for(i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        p = table[i];

        while(p != NULL)
        {
            printf("%d -> ", p->data);
            p = p->next;
        }

        printf("NULL\n");
    }
}
