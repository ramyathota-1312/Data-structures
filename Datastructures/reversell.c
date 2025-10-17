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
void reverse();
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
	}
	else 
	{
		end->next=newnode;
		end=newnode;
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
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
}
void reverse()
{
	if(head==NULL)
	{
		printf("\n List is empty....");
		return;
	}
	struct node*prev=NULL,*curr=head,*next1=NULL;
	end=head;
	while(curr!=NULL)
	{
		next1=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next1;
	}
	head=prev;
	printf("Nodes are reversed");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n******menu*******");
		printf("\n 1.create\n2.Display\n3.Reverse\n4.exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_nodes();
			break;
			case 2:display();
			break;
			case 3:reverse();
			break;
			case 4:exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	return 0;
}
