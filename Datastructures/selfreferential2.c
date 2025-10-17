#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data[20];
	struct node *next;
};
int main()
{
	struct node n1,n2,n3,*ptr;
	printf("\nEnter data into node1 :");
	scanf("%s",&n1.data);
	n1.next=&n2;
	printf("\nEnter data into node2 :");
	scanf("%s",&n2.data);
	n2.next=&n3;
	printf("\nEnter data into node3 :");
	scanf("%s",&n3.data);
	n3.next=NULL;
	ptr=&n1;
		while(ptr!=NULL)
	{
		printf("\n data at node is %s",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
