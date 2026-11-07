//#include <stdio.h>

#define MAX 100

int queue[MAX], priority[MAX];
int n = 0;

void display()
{
    if (n == 0)
    {
        printf("\nPriority Queue is Empty\n");
        return;
    }

    printf("\nElement\tPriority\n");
    printf("--------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

void enqueue()
{
    if (n == MAX)
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    int item, p;

    printf("Enter element: ");
    scanf("%d", &item);

    printf("Enter priority: ");
    scanf("%d", &p);

    queue[n] = item;
    priority[n] = p;
    n++;

    printf("\nElement inserted successfully.\n");

    display();
}

void dequeue()
{
    if (n == 0)
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    int pos = 0;

    // Find highest priority element
    for (int i = 1; i < n; i++)
    {
        if (priority[i] < priority[pos])
        {
            pos = i;
        }
    }

    printf("\nDeleted Element: %d", queue[pos]);
    printf("\nPriority: %d\n", priority[pos]);

    // Shift remaining elements
    for (int i = pos; i < n - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;

    display();
}

int main()
{
    int choice;

    do
    {
        printf("\n\n----- PRIORITY QUEUE -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}