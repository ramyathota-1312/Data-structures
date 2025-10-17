#include<stdio.h>
#include<stdlib.h>
#define size 5
int Q[size];
int front=-1;
int rear=-1;
void enq(int);
int deq();
void display();
void enq(int ele)
{
	if(rear==size-1)
	{
		printf("QUEUE is overflow\n");
		return;
	}
	if(rear==-1)
	front=0;
	rear++;
	Q[rear]=ele;
	
}
int deq()
{
	int x;
	if(front==-1)
	{
		printf("QUEUE is underflow\n");
		return -1;
	}
	x=Q[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	front++;
	return x;
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("QUEUE is underflow\n");
	}
	else
	{
		printf("queue elements are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",Q[i]);
		}
	}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n***INDEX***\n");
		printf("1.ENQUEUE\n2.DEQUEUE\n");
		printf("3.DISPLAY\n4.Exit\n");
		printf("Enter Your Choice:");
	            scanf("%d",&ch);
    	switch(ch)
    	{
		  case 1:
		  	printf("\nEnter element:");
		  	scanf("%d",&x);
		  	enq(x);
		  	break;
		  case 2:
		  	x=deq();
		  	if(x!=-1)
		  	  printf("Popped element is %d\n",x);
		  	break;  
	      case 3:
	      	display();
	      	break;
		  case 4:
		  	exit(0);
		  default:printf("\n--Invalid choice--");
    	}

	}
	return 0;
}

