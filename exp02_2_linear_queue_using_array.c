//name of programme ; Queue
//Author :Shanu S
//aim ; queue using array
//Date :27/07/2026
#include <stdio.h>
#define Max 10
int queue[Max];
int front=-1,back=-1;

// Function Prototypes
// Inserts a value at the rear end of the queue
void enqueue(int value);
// Removes and returns the element at the front of the queue
int dequeue(void);
// Returns the element at the front of the queue without removing it
int seefront(void);
// Returns 1 if the queue is empty, otherwise 0
int isEmpty(void);
// Returns 1 if the queue is full, otherwise 0
int isFull(void);
// Displays all the elements present in the queue
void Printqueue(void);

int main()
{int choice =-1 ;
    printf("1.Enqueue\n 2.Dequeue\n 3.See first \n 4.see queue\n 5.Exit\n");
    while (choice !=5)
    {printf("current queue:\n");
        Printqueue();
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        { case 1:
            printf("enter the element: ");
            int val;
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
                { int dequeued = dequeue();
                    if (dequeued != -1)
                        printf("element dequeued ;%d \n",dequeued);
                    break;
                }
            case 3:
                { int topmost=seefront();
                    if (topmost !=-1)
                        printf ("top most element is %d\n",topmost);
                    break;
                }
            case 4:
                Printqueue();
                break;
            case 5:
                printf("exited\n");
                break;
            default:
                printf("wrong choice\n");
                break;
        }
    }
}

void enqueue(int value)
{ if (front==-1)
    front ++;
    if (isFull()==1)
        printf("Queue is Full\n");
    else
    {back++;
        queue[back]=value;
        printf("Queued\n");
    }
}
int dequeue()
{ if (isEmpty()==1)
    {printf("Queue is Empty\n");
        return -1;}
    else
        return (queue[front++]);
}
int seefront()
{
    if (isEmpty()==1)
    {printf("Queue is Empty\n");
        return -1;}
    else
        return(queue[front]);
}

void Printqueue()
{if (isEmpty()==1)
    {printf("Queue is Empty\n");
    }
    else
    { for (int i=front;i<=back;++i)
        printf("%d\t",queue[i]);
        printf("\n");
    }
}
int isEmpty()
{ if (front>back)
    return 1;
    else if (front==-1)
        return 1;
    else
        return 0;
}

int isFull(){
    if (back==Max-1)
        return 1;
    else
        return 0;
}
