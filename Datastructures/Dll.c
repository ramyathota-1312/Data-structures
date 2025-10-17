 #include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*prev;
	int data;
	struct node*next;
};
struct node*create_node();
void create_list();
void display();
void reverse_order();
void insert_first();
void insert_last();
void insert();
void delete_node();
void search();
struct node*head=NULL,*end=NULL;
int count=0;
struct node*create_node()
{
	int info;
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("cannot allocate memory");
		return;
	}
	printf("\nEnter data into a node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void create_list()
{
	struct node*newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	count++;
	printf("....node is created...\n");
}
void display()
{
    struct node*temp;
    if(head==NULL)	
    {
    	printf("List is empty\n");
    	return;
    }
    temp=head;
    printf("\nList is:\n");
    while(temp!=NULL)
    {
    	printf("%d->",temp->data);
    	temp=temp->next;
	}
	printf("NULL\n");
}
void reverse_order()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=end;
	printf("\nList elements(Backward):\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("Head Null\n");
}
void insert_first()
{
	struct node*newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
	count++;
	printf("Node is added\n");
}
void insert_last()
{
	struct node*newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	count++;
	printf("Node is added\n");
}
void insert()
{
	struct node*newnode,*temp,*curr;
	int pos,i;
	printf("\nEnter position to insert:");
	scanf("%d",&pos);
	if(pos<1||pos>count+1)
	{
		printf("Invalid position\n");
		return;
	}
	if(pos==1)
	{
		insert_first();
		return;
	}
	else if(pos==count+1)
	{
		insert_last();
		return;
	}
	newnode=create_node();
	curr=head;
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	newnode->next=curr;
	newnode->prev=temp;
	curr->prev=newnode;
	temp->next=newnode;
	count++;
	printf("Node is added at position %d\n",pos);
}
void delete_node()
{
	int pos,i;
	struct node*curr,*temp;
	if(head==NULL)
	{
		printf("List is empty,Nothing to delete\n");
		return;
	}
	printf("Enter position to delete:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("Invalid position\n");
		return;
	}
	temp=head;
	if(pos==1)
	{
		head=head->next;
		if(head!=NULL)
		{
			head->prev=NULL;
		}
		else
		{
			end=NULL;
		}
		free(temp);
	}
	else if(pos==count)
	{
		temp=end;
		end=end->prev;
		end->next=NULL;
		free(temp);
	}
	else
	{
		curr=head;
		for(i=1;i<pos;i++)
		{
			temp=curr;
			curr=curr->next;
		}
		temp->next=curr->next;
		curr->next->prev=temp;
		free(curr);
	}
	count--;
	printf("...Node at position %d is deleted..\n",pos);
}
void search()
{
	int key;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("\nEnter element to be search:");
	scanf("%d",&key);
	int found=0;
	struct node*curr=head;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("Element is found");
			return;
			found=1;
		}
		curr=curr->next;
	}
	if(found=0)
	{
		printf("Element is not found");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n******menu*******");
		printf("\n 1.create\n2.Display\n3.Reverse\n4.Insert a node at first");
		printf("\n5.Insert a node at last\n6.Insert at any node\n7.Delete operation\n8.search\n");
		printf("\n9.exit\n");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_list();
			break;
			case 2:display();
			break;
			case 3:reverse_order();
			break;
		   	case 4:insert_first();
			break;
			case 5:insert_last();
			break;
			case 6:insert();
			break;
			case 7:delete_node();
			break;
			case 8:search();
			break;
			case 9:exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	return 0;
}
