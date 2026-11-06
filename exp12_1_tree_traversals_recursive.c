// Name : Tree Traversals - Recursive
// Aim : To create a binary tree and perform inorder, preorder and postorder traversals using recursion
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function Prototypes
// Creates a binary tree recursively (-1 means no node)
struct node *createTree();
// Frees all the nodes of the tree
void freeTree(struct node *t);
// Prints the tree in inorder (Left, Root, Right) using recursion
void inorder(struct node *t);
// Prints the tree in preorder (Root, Left, Right) using recursion
void preorder(struct node *t);
// Prints the tree in postorder (Left, Right, Root) using recursion
void postorder(struct node *t);

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Tree Traversals (Recursive) ---");
        printf("\n1. Create Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                // Delete the old tree before creating a new one
                freeTree(root);
                root = NULL;

                printf("Enter root node.\n");
                root = createTree();
                break;

            case 2:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

struct node *createTree()
{
    int data;
    struct node *newnode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    // -1 represents an empty subtree
    if(data == -1)
        return NULL;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    printf("Enter left child of %d\n", data);
    newnode->left = createTree();

    printf("Enter right child of %d\n", data);
    newnode->right = createTree();

    return newnode;
}

void freeTree(struct node *t)
{
    // Free all nodes of the tree (postorder)
    if(t == NULL)
        return;

    freeTree(t->left);
    freeTree(t->right);
    free(t);
}

void inorder(struct node *t)
{
    // Left, Root, Right
    if(t == NULL)
        return;

    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

void preorder(struct node *t)
{
    // Root, Left, Right
    if(t == NULL)
        return;

    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void postorder(struct node *t)
{
    // Left, Right, Root
    if(t == NULL)
        return;

    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);
}
