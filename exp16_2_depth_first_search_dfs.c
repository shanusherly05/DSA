// Name : Depth First Search (DFS) on Graphs
// Aim : To create an undirected graph using an adjacency matrix and traverse it using DFS
// Author : Shanu S
// Date : 05/10/26

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n = 0;

// Function Prototypes
// Creates an undirected graph using an adjacency matrix
void createGraph();
// Displays the adjacency matrix of the graph
void displayMatrix();
// Performs depth first search recursively from vertex v
void dfsRecursive(int v);
// Performs depth first search using an explicit stack
void dfsIterative(int start);

int main()
{
    int choice, start, i;

    while(1)
    {
        printf("\n--- DFS on Graph ---");
        printf("\n1. Create Graph");
        printf("\n2. Display Adjacency Matrix");
        printf("\n3. DFS Traversal (Recursive)");
        printf("\n4. DFS Traversal (Iterative)");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                if(n == 0)
                {
                    printf("Create the graph first.\n");
                    break;
                }

                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if(start < 0 || start >= n)
                {
                    printf("Invalid vertex.\n");
                    break;
                }

                // Reset the visited array before every traversal
                for(i = 0; i < n; i++)
                    visited[i] = 0;

                printf("DFS Traversal (Recursive): ");
                dfsRecursive(start);
                printf("\n");
                break;

            case 4:
                if(n == 0)
                {
                    printf("Create the graph first.\n");
                    break;
                }

                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if(start < 0 || start >= n)
                    printf("Invalid vertex.\n");
                else
                    dfsIterative(start);
                break;

            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void createGraph()
{
    int edges, i, j, u, v;

    printf("Enter number of vertices (maximum %d): ", MAX);
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }

    // Initialize the adjacency matrix with zeros
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 1; i <= edges; i++)
    {
        printf("Enter edge %d (u v): ", i);
        scanf("%d %d", &u, &v);

        if(u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid vertices. Enter the edge again.\n");
            i--;
            continue;
        }

        // Undirected graph: set both entries
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Graph created successfully.\n");
}

void displayMatrix()
{
    int i, j;
    if(n == 0)
    {
        printf("Create the graph first.\n");
        return;
    }

    printf("Adjacency Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", adj[i][j]);

        printf("\n");
    }
}

void dfsRecursive(int v)
{
    int i;

    // Visit the current vertex
    visited[v] = 1;
    printf("%d ", v);

    // Recursively visit every unvisited neighbour
    for(i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && !visited[i])
            dfsRecursive(i);
    }
}

void dfsIterative(int start)
{
    int stack[MAX * MAX];
    int top = -1;
    int seen[MAX] = {0};
    int v, i;

    stack[++top] = start;

    printf("DFS Traversal (Iterative): ");

    while(top != -1)
    {
        // Remove the vertex on top of the stack
        v = stack[top--];

        if(!seen[v])
        {
            seen[v] = 1;
            printf("%d ", v);

            // Push neighbours in reverse order so the smallest is visited first
            for(i = n - 1; i >= 0; i--)
            {
                if(adj[v][i] == 1 && !seen[i])
                    stack[++top] = i;
            }
        }
    }

    printf("\n");
}
