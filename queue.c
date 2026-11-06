
//name of programme ; Queue
//Author :Shanu S
//aim ; queue using array
//Date  :27/07/2026
#include <stdio.h>
#define Max 10
int queue[Max];
int front=-1,back=-1;

void enqueue(int value);
int dequeue(void);
int seefront(void);
int isEmpty(void);
int isFull(void);
void Printqueue(void);


int main()
 {int choice =-1 ;
       printf("1.Enqueue\n 2.Dequeue\n 3.See first \n 4.see queue\n 5.Exit\n");
     while (choice !=5)
    {printf("current queue:\n");
     Printqueue();
     printf("enter your choice\n ");
     scanf("%d",&choice);
switch(choice)
{ case 1:
  printf("enter the element");
  int val;
  scanf("%d",&val);
  enqueue(val);
  break;

 case 2:
{  int dequeued = dequeue();
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
  printf("exited");
  break;
default:
 printf("wrong choice");
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
          {printf("Queue is Empty");
           return -1;}
         else 
           return (queue[front++]);
       }
int seefront()
      { 
          if (isEmpty()==1)
           {printf("Queue is Empty");
            return -1;}
          else
                return(queue[back]);
      }

void Printqueue()
         {if (isEmpty()==1)
           {printf("Queue is Empty");
            }
          else 
            { for (int i=back;i>=front;--i)
                printf("%d\t",queue[i]);
                printf("\n");
            }
          }
int isEmpty()
        { if (front>back)
           return 1;
         else if (front==back==-1)
           return 1;
         else
           return 0;
        }

int isFull(){
      if (back==Max)
           return 1;
      else
          return 0;
       }
