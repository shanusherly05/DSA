// Name   : Breadth First Search (BFS) on Graphs
// Aim    : To create an undirected graph using an adjacency matrix and traverse it using BFS
// Author : Shanu S
// Date   : 05/10/26

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int n = 0;

// Function Prototypes
void createGraph();
void displayMatrix();
void bfs(int start);

int main()
{
    int choice, start;

    while(1)
    {
        printf("\n--- BFS on Graph ---");
        printf("\n1. Create Graph");
        printf("\n2. Display Adjacency Matrix");
        printf("\n3. BFS Traversal");
        printf("\n4. Exit");

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
                    printf("Invalid vertex.\n");
                else
                    bfs(start);
                break;

            case 4:
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

void bfs(int start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;
    int v, i;

    // Mark the starting vertex as visited and add it to the queue
    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        // Remove a vertex from the front of the queue
        v = queue[front++];
        printf("%d ", v);

        // Add all unvisited neighbours to the queue
        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}
