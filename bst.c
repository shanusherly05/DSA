// Name   : Binary Search Tree - All Operations
// Aim    : To implement insertion, deletion, search, traversals, minimum, maximum, height and node count on a BST
// Author : Shanu S
// Date   : 05/10/26

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
struct node *insert(struct node *t, int data);
struct node *deleteNode(struct node *t, int data);
struct node *search(struct node *t, int key);
struct node *findMin(struct node *t);
struct node *findMax(struct node *t);
void inorder(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t);
int height(struct node *t);
int countNodes(struct node *t);

int main()
{
    int choice, data;
    struct node *result;

    while(1)
    {
        printf("\n--- Binary Search Tree ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Find Minimum");
        printf("\n8. Find Maximum");
        printf("\n9. Height of Tree");
        printf("\n10. Count Nodes");
        printf("\n11. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                if(root == NULL)
                {
                    printf("Tree is empty.\n");
                    break;
                }

                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                if(root == NULL)
                {
                    printf("Tree is empty.\n");
                    break;
                }

                printf("Enter data to search: ");
                scanf("%d", &data);

                result = search(root, data);

                if(result != NULL)
                    printf("Element %d found.\n", data);
                else
                    printf("Element %d not found.\n", data);
                break;

            case 4:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 6:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 7:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Minimum element: %d\n", findMin(root)->data);
                break;

            case 8:
                if(root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Maximum element: %d\n", findMax(root)->data);
                break;

            case 9:
                printf("Height of tree (number of levels): %d\n", height(root));
                break;

            case 10:
                printf("Number of nodes: %d\n", countNodes(root));
                break;

            case 11:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

struct node *insert(struct node *t, int data)
{
    struct node *newnode;

    // Empty position found, so create the new node here
    if(t == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;

        printf("Node inserted successfully.\n");
        return newnode;
    }

    // Smaller values go to the left, larger values go to the right
    if(data < t->data)
        t->left = insert(t->left, data);
    else if(data > t->data)
        t->right = insert(t->right, data);
    else
        printf("Duplicate value is not allowed.\n");

    return t;
}

struct node *deleteNode(struct node *t, int data)
{
    struct node *temp;

    if(t == NULL)
    {
        printf("Element not found.\n");
        return NULL;
    }

    if(data < t->data)
    {
        t->left = deleteNode(t->left, data);
    }
    else if(data > t->data)
    {
        t->right = deleteNode(t->right, data);
    }
    else
    {
        // Node with no left child (leaf node or only right child)
        if(t->left == NULL)
        {
            temp = t->right;
            free(t);

            printf("Node deleted successfully.\n");
            return temp;
        }

        // Node with only left child
        if(t->right == NULL)
        {
            temp = t->left;
            free(t);

            printf("Node deleted successfully.\n");
            return temp;
        }

        // Node with two children: replace with inorder successor
        temp = findMin(t->right);
        t->data = temp->data;

        // Delete the inorder successor from the right subtree
        t->right = deleteNode(t->right, temp->data);
    }

    return t;
}

struct node *search(struct node *t, int key)
{
    // Return NULL if the element is not present
    if(t == NULL || t->data == key)
        return t;

    if(key < t->data)
        return search(t->left, key);

    return search(t->right, key);
}

struct node *findMin(struct node *t)
{
    // The leftmost node holds the smallest value
    while(t->left != NULL)
        t = t->left;

    return t;
}

struct node *findMax(struct node *t)
{
    // The rightmost node holds the largest value
    while(t->right != NULL)
        t = t->right;

    return t;
}

void inorder(struct node *t)
{
    // Left, Root, Right (gives sorted order in a BST)
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

int height(struct node *t)
{
    int leftHeight, rightHeight;

    // An empty tree has height 0
    if(t == NULL)
        return 0;

    leftHeight = height(t->left);
    rightHeight = height(t->right);

    // Height is one more than the taller subtree
    if(leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

int countNodes(struct node *t)
{
    // Count the left subtree, right subtree and the current node
    if(t == NULL)
        return 0;

    return countNodes(t->left) + countNodes(t->right) + 1;
}
