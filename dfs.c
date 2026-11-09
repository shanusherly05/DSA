
// Name   : Graph Traversal Using Adjacency List
// Aim    : To create a graph using adjacency list and
//          traverse it using BFS and DFS
// Author : Shanu S
// Date   : 09/11/26

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[MAX];
int visited[MAX], n;

// Function Prototypes
void createGraph();
void insertEdge(int u, int v);
void BFS(int start);
void DFS(int start);
void resetVisited();

int main()
{
    int choice, start;

    createGraph();

    do
    {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &start);

                if(start < 0 || start >= n)
                {
                    printf("Invalid vertex\n");
                    break;
                }

                resetVisited();
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;

            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);

                if(start < 0 || start >= n)
                {
                    printf("Invalid vertex\n");
                    break;
                }

                resetVisited();
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}

// Function to insert an edge
void insertEdge(int u, int v)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->vertex = v;
    newnode->next = adj[u];
    adj[u] = newnode;
}

// Function to create graph
void createGraph()
{
    int i, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        insertEdge(u, v);
        insertEdge(v, u);
    }
}

// Function to reset visited array
void resetVisited()
{
    int i;

    for(i = 0; i < n; i++)
        visited[i] = 0;
}

// Function for BFS traversal
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    struct node *temp;
    int vertex;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        temp = adj[vertex];

        while(temp != NULL)
        {
            if(visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }
}

// Function for DFS traversal
void DFS(int start)
{
    struct node *temp;

    visited[start] = 1;
    printf("%d ", start);

    temp = adj[start];

    while(temp != NULL)
    {
        if(visited[temp->vertex] == 0)
            DFS(temp->vertex);

        temp = temp->next;
    }
}
