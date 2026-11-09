
// Name   : Graph Traversal Using BFS and DFS
// Aim    : To create a graph using an adjacency matrix and
//          traverse it using BFS and DFS
// Author : Shanu S
// Date   : 09/11/26

#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

// Function Prototypes
void createGraph();
void BFS(int start);
void DFS(int start);
void resetVisited();

int main()
{
    int choice, start;

    createGraph();

    do
    {
        printf("\n\n--- Graph Traversal Menu ---\n");
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

// Function to create graph
void createGraph()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        n = 0;
        return;
    }

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

// Function to reset visited array
void resetVisited()
{
    int i;

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

// Function for BFS traversal
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i, vertex;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(adj[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

// Function for DFS traversal
void DFS(int start)
{
    int i;

    visited[start] = 1;
    printf("%d ", start);

    for(i = 0; i < n; i++)
    {
        if(adj[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
