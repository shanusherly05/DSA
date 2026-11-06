//name ; DOuble ended Queue
//aim ;implementation of Double ended queue using array
//Author ;Shanu S
//date ;3/08/2026

#include <stdio.h>
#define MAX 5

// Function Prototypes
// Inserts an element at the front end of the dequeue
void insertfront();
// Inserts an element at the rear end of the dequeue
void insertrear();
// Deletes an element from the front end of the dequeue
void deletefront();
// Deletes an element from the rear end of the dequeue
void deleterear();
// Displays all the elements from front to rear
void display();

int queue[MAX];
int front=-1,rear=-1;

int main()
{ int ch;
    while (1)
    {printf("1.insert front \n 2. insert rear \n 3.delete front \n 4.delete rear \n 5.display\n 6.Exit \n");
        printf("\n enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {case 1:insertfront(); break;
            case 2:insertrear(); break;
            case 3:deletefront(); break;
            case 4:deleterear(); break;
            case 5:display(); break;
            case 6:return 0;
            default: printf("invaild choice\n");
        }
    }
}

void insertfront()
{ int item;
    if((front==0 && rear ==MAX-1)||(front==rear+1))
    {printf("queue Full\n");
        return;
    }
    printf("enter the element\n ");
    scanf("%d",&item);
    if (front==-1)
        front=rear=0;
    else if (front==0)
        front=MAX-1;
    else
        front--;
    queue[front]=item;
}

void insertrear()
{ int item;
    if((front==0 && rear ==MAX-1)||(front==rear+1))
    {printf("queue Full\n");
        return;
    }
    printf("enter the element\n ");
    scanf("%d",&item);
    if (front==-1)
        front=rear=0;
    else if (rear==MAX-1)
        rear=0;
    else
        rear++;
    queue[rear]=item;
}

void deletefront()
{ if(front==-1)
    {printf("queue Empty\n");
        return;
    }
    printf("deleted = %d\n",queue[front]);
    if (front==rear)
        front=rear=-1;
    else if (front==MAX-1)
        front=0;
    else
        front++;
}

void deleterear()
{ if(front==-1)
    {printf("queue Empty\n");
        return;
    }
    printf("deleted = %d\n",queue[rear]);
    if (front==rear)
        front=rear=-1;
    else if (rear==0)
        rear=MAX-1;
    else
        rear--;
}

void display()
{int i;
    if(front==-1)
    {printf("queue Empty\n");
        return;
    }
    printf("Queue ;\n ");
    i=front;
    while(1)
    {printf("%d \n ",queue[i]);
        if (i==rear)
            break;
        i=(i+1)%MAX;
    }
}
