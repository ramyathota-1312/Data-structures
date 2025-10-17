#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head=NULL,*end=NULL;
void create_nodes();
void display();
void insertfirst();
void insertlast();
void insert();
void deleteatfirst();
void deleteatlast();
void deleteatanynode();
int count=0;
void create_nodes()
{
		int info;
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Memory full");
		return;
	}
	printf("\n Enter data into a node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
		end->next=head;
	}
	else 
	{
		end->next=newnode;
		end=newnode;
		end->next=head;
	}
	count++;
	printf("\n Node created or added");
}
void display()
{
  	struct node*temp;
	if(head==NULL)
	{
		printf("\n List is empty....");
		return;
	}
	temp=head;
	printf("List elements are....");
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	while(temp!=head);
	{
		temp=temp->next;
	}
}
void insertfirst()
{
	int info;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory is full\n");
		return;
	}
	printf("\n Enter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;
	head=newnode;
	end->next=newnode;
	count++;
	printf("\n Node is created");
}
void insertlast()
{
		int info;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	printf("\n Enter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	end->next=newnode;
	end=newnode;
	end->next=head;
	count++;
	printf("\n Node is added");
}
void insert()
{
		int info,pos,i;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	printf("\n Enter data into node");
	scanf("%d",&info);
	printf("\n Enter position value");
	scanf("%d",&pos);
	newnode->data=info;
	newnode->next=NULL;
	if(pos<0||pos>count)
	{
		printf("invalid position\n");
		free(newnode);
		return;
	}
	struct node*temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
	printf("\n Node is added");
}
void deleteatfirst()
{
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	struct node*temp=head;
	if(temp->next==head)
	{
		free(temp);
		head=NULL;
	}
	else
	{
		struct node*last=head;
		while(last->next!=head)
		{
			last=last->next;
		}
		head=head->next;
		last->next=head;
	    free(temp);
	}
	count--;
	printf("Node is deleted");
}
void deleteatlast()
{
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	struct node*temp=head,*prev=NULL;
	if(temp->next==head)
	{
		free(temp);
		head=NULL;
	}
	else
	{
	    while(temp->next!=head)
	    {
	    	prev=temp;
		    temp=temp->next;
    	}
    	prev->next=head;
    	free(temp);
	}
	count--;
	printf("Node is deleted");
}
void deleteatanynode()
{
	int pos,i;
   if(head==NULL)
	{
		printf("Empty");
		return;
	}
	printf("Enter the position");
	scanf("%d",&pos);
	struct node*temp=head;
	if(pos==1)
	{
	 deleteatfirst(head);
	 return;
	}	
	for(i=1;temp!=NULL&&i<pos-1;i++)
	{
		temp=temp->next;
	}
	if(temp==NULL||temp->next==head)
	{
		printf("Position is out of range");
		return;
	}
    struct node*nodetodelete=temp->next;
	temp->next=nodetodelete->next;
	free(nodetodelete);
	count--;
	printf("Node is deleted");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n******menu*******");
		printf("\n 1.create\n2.Display\n3.Insert a node at first\n4.Insert a node at last");
		printf("\n5.Insert at any position\n6.Delete at first\n7.Delete at last\n8.Delete at any node\n9.exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_nodes();
			break;
			case 2:display();
			break;
			case 3:insertfirst();
			break;
			case 4:insertlast();
			break;
			case 5:insert();
			break;
			case 6:deleteatfirst();
			break;
			case 7:deleteatlast();
			break;
			case 8:deleteatanynode();
			break;
			case 9:exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	return 0;
}
