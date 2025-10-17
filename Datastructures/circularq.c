#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void enq(int);
int deq();
void display();
int cq[SIZE];
int front=-1,rear=-1;
void enq(int ele)
{
 if((front==0&&rear==SIZE-1)||(rear+1)%SIZE==front)
 {
 	printf("Circular queue  is full\n");
 	return;
 }
 else
 {
 	rear=(rear+1)%SIZE;
 	if(front==-1)
 	  front=0;
	   cq[rear]=ele;
	   printf("%d is placed in circular queue\n",ele);	
 }
}
int deq()
{
	if(front==-1)
	{
		printf("Circular queue is empty\n");
		return -1;
	}
	int ele=cq[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%SIZE;
	}
	return ele;
}
void display()
{
	if(front==-1)
	{
		printf("Circular queue is empty\n");
		return;
	}
	printf("Circular queue elements are:");
	int i=front;
	while(1)
	{
		printf("\t%d",cq[i]);
		if(i==rear)
		break;
		i=(i+1)%SIZE;
	}
	printf("\n");
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
		  	  printf("%d is removed from the circular queue\n",x);
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


