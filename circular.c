//name ; circular queue
//aim ;implementation of circular queue using array
//Author ;Shanu S
//date ;3/08/2026

#include <stdio.h>
#define MAX 5

void enqueue();
void dequeue();
void display();

int queue[MAX];
int front=-1,rear=-1;

int main()
  { int ch;
    while (1)
    {printf("1.enqueue \n 2.dequeue\n 3.display\n 4.Exit \n");
     printf("\n enter choice");
     scanf("%d",&ch);
     switch(ch)
      {case 1:enqueue(); break;
       case 2:dequeue(); break;
       case 3:display(); break;
       case 4:return 0;
       default: printf("invaild choice\n");
      }
    }
  }

void enqueue()
  { int item;
    if((rear+1) % MAX==front)
    {printf("queue overflow");
     return;
    }
    printf("enter the element\n ");
    scanf("%d",&item);
    if (front==-1)
      front=rear=0;
    else
      rear=(rear+1)%MAX;
    queue[rear]=item;
  }
void dequeue()
   { if(front==-1)
     {printf("queue underflow");
      return;
     }
     printf("deleted  element is  %d ",queue[front]);
     if (front==rear)
       front=rear=-1;
     else
       front=(front+1)%MAX;
    }
void display()
    {int i;
      if(front==-1)
        {printf("queue Empty");
         return;
         }
      printf("Queue ;");
      i=front;
      while(1)
         {printf("%d \n ",queue[i]);
          if (i==rear)
           break;
          i=(i+1)%MAX;
          }
     }


