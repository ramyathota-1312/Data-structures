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
void search();
void replace();
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
void insertfirst()
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
	newnode->next=head;
	head=newnode;
	count++;
	printf("\n Node is added");
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
	if(pos<1||pos>count+1)
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
	head=head->next;
	free(temp);
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
	struct node*prev,*curr;
	curr=head;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	free(curr);
	end=prev;
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
	if(pos<1||pos>count)
	{
	 printf("Invalid");
	 return;
	}	
	struct node*prev,*curr;
	curr=head;
	for(i=1;i<pos;i++)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	free(curr);
	count--;
	printf("Node is deleted");
}
void search()
{
	int key;
if(head==NULL)
	{
		printf("Empty");
		return;
	}
	printf("Enter key element:");
	scanf("%d",&key);
	struct node*curr=head;int found=0;
	while(curr!=NULL)
	{
	if(curr->data==key)	
	{
		printf("Element found");
		found=1;
		break;
	}
	curr=curr->next;
	}	
    if(found==0)
	{	
		printf("element is not found");
	}
}
void replace()
{
	int key,ele;
	struct node*curr=head;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	printf("\nEnter element to be replaced");
	scanf("%d",&key);
	printf("Enter element to replace");
	scanf("%d",&ele);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			curr->data=ele;
			printf("\nNode is updated");
			return;
		}
		curr=curr->next;
	}
	printf("Element is replaced");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n******menu*******");
		printf("\n 1.create\n2.Display\n3.Insert a node at first\n4.Insert a node at last");
		printf("\n5.Insert\n6.Delete at first\n7.Delete at last\n8.Delete at any node\n9.search\n10.Replace\n11.exit");
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
			case 9:search();
			break;
			case 10:replace();
			break;
			case 11:exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	return 0;
}
