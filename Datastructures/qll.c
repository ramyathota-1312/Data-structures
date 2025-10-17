#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
	struct queue *next;	
}Q;
Q *front=NULL,*rear=NULL;
void enq(int );
void display();
int deq();
void enq(int info)
{
	Q *newnode=(Q *)malloc(sizeof(Q));
	if(newnode==NULL)
	{
		printf("Memory is full...");
		return;
	}
	newnode->data=info;
	newnode->next=NULL;
	if (rear==NULL)
	{
		front=rear=newnode;
		printf("\n Element pushed into the queue...");
		return;
	}
	rear->next=newnode;
	rear=newnode;
	printf("\n Element pushed into the queue...");
}
void display()
{
	Q *temp;
	if(front==NULL)
	{
	    printf("\n QUEUE Under Flow...");
	    return ;
	}
	temp=front;
	printf("\nQUEUE Uelements are:\n");
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}	
}
int deq()
{
	int x;
	if(front==NULL)
	{
	    printf("\nQueue Under Flow...");
	    return -1;
	}
	Q *temp=front;
	x=front->data;
	front=front->next;
	if(front==NULL)
	rear=NULL;
	return x;
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

