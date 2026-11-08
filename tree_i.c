// Name   : Tree Traversals - Iterative
// Aim    : To create a binary tree and perform inorder, preorder, postorder and level order traversals without recursion
// Author : Shanu S
// Date   : 05/10/26

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function Prototypes
struct node *createTree();
void freeTree(struct node *t);
void inorder();
void preorder();
void postorder();
void levelOrder();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Tree Traversals (Iterative) ---");
        printf("\n1. Create Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Level Order Traversal");
        printf("\n6. Exit");

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
                inorder();
                break;

            case 3:
                preorder();
                break;

            case 4:
                postorder();
                break;

            case 5:
                levelOrder();
                break;

            case 6:
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

void inorder()
{
    struct node *stack[MAX];
    struct node *curr = root;
    int top = -1;

    if(root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Inorder: ");

    while(curr != NULL || top != -1)
    {
        // Go to the leftmost node and push every node on the way
        while(curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }

        // Visit the node, then move to its right subtree
        curr = stack[top--];
        printf("%d ", curr->data);

        curr = curr->right;
    }

    printf("\n");
}

void preorder()
{
    struct node *stack[MAX];
    struct node *curr;
    int top = -1;

    if(root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Preorder: ");

    stack[++top] = root;

    while(top != -1)
    {
        // Visit the node on top of the stack
        curr = stack[top--];
        printf("%d ", curr->data);

        // Push right first so that left is processed first
        if(curr->right != NULL)
            stack[++top] = curr->right;

        if(curr->left != NULL)
            stack[++top] = curr->left;
    }

    printf("\n");
}

void postorder()
{
    struct node *stack[MAX];
    struct node *curr = root;
    struct node *lastVisited = NULL;
    struct node *topNode;
    int top = -1;

    if(root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Postorder: ");

    while(curr != NULL || top != -1)
    {
        if(curr != NULL)
        {
            // Keep moving to the left
            stack[++top] = curr;
            curr = curr->left;
        }
        else
        {
            topNode = stack[top];

            // Move to the right subtree if it is not visited yet
            if(topNode->right != NULL && lastVisited != topNode->right)
            {
                curr = topNode->right;
            }
            else
            {
                // Both subtrees are done, so visit the node
                printf("%d ", topNode->data);
                lastVisited = stack[top--];
            }
        }
    }

    printf("\n");
}

void levelOrder()
{
    struct node *queue[MAX];
    struct node *curr;
    int front = 0, rear = -1;

    if(root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Level Order: ");

    queue[++rear] = root;

    while(front <= rear)
    {
        // Remove a node from the front of the queue
        curr = queue[front++];
        printf("%d ", curr->data);

        // Add its children at the rear of the queue
        if(curr->left != NULL)
            queue[++rear] = curr->left;

        if(curr->right != NULL)
            queue[++rear] = curr->right;
    }

    printf("\n");
}
