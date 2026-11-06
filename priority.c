//name ; Priorty Queue
//aim ;implementation of Priority queue using array
//Author ;Shanu S
//date ;3/08/2026

#include <stdio.h>
#define MAX 5

void insert();
void Delete();
void display();
void peek();

int data[MAX],pr[MAX];
int count=0;

int main()
  { int ch;
    while (1)
    {printf("1.insert \n 2. delete \n  3.display\n  4.peek  \n5.Exit \n ");
     printf("\n enter choice");
     scanf("%d",&ch);
     switch(ch)
      {case 1:insert(); break;
       case 2:Delete(); break;
       case 3:display(); break;
       case 4:peek(); break;
       case 5:return 0;
       default: printf("invaild choice\n");
      }
    }
  }
void insert()
   { int item,p,i;
     if (count==MAX)
     {printf("queue is full");
      return;
     }
     printf("Enter Element :");
     scanf("%d",&item);
     printf("Enter the priority ");
     scanf("%d",&p);
     i=count-1;
     while(i>=0 && pr[i]>p)
       { data[i+1]=data[i];
         pr[i+1]=pr[i];
         i--;
       }
     data[i+1]=item;
     pr[i+1]=p;
     count++;
   }
void Delete()
    { int i;
      if (count==0)
         {printf("queue is empty\n ");
          return;
          }
         printf("Deleted = %d\n ",data[0]);
         for(i=0;i<count-1;i++)
           { data[i]=data[i+1];
             pr[i]=pr[i+1];
           }
       count--;
    }

void display()
      { int i; 
          if (count==0)
            {printf("queue is empty\n ");
             return;
            }
         printf("\n Element  \t  priority \n");
         for(i=0;i<count;i++)
         { printf("\n %d \t %d \n",data[i],pr[i]);
         }
      }
void peek()
     {if (count == 0)
      { printf("queue is empty");
        return;
       }
      printf("\n Highest priority element: %d with priority: %d\n", data[0], pr[0]);
     }
