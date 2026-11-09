// Name : Binary Search Tree Operations
// Aim  : To implement insertion, deletion, search and traversals of a BST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Insert a node
struct node *insert(struct node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search an element
void search(struct node *root, int key)
{
    if(root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(root->data == key)
    {
        printf("Element found\n");
        return;
    }

    if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Find minimum value node
struct node *findMin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

// Delete a node
struct node *deleteNode(struct node *root, int key)
{
    struct node *temp;

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // Node has no child or one child
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    struct node *root = NULL;
    int choice, value;

    while(1)
    {
        printf("\n\n--- BST OPERATIONS ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                search(root, value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}