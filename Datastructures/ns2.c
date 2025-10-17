#include<stdio.h>
#include<string.h>
struct student
{
	char name[30];
	struct address
	{
		int dno;
		char city[30];
		char street[40];
	}add;
	float avg;
};
int main()
{
	struct student s1;
	printf("Enter name,dno,city,street,avg");
   scanf("%s",s1.name);
   scanf("%d",&s1.add.dno);
   scanf("%s",s1.add.city);
   scanf("%s",s1.add.street);
   scanf("%f",&s1.avg);
   	printf("%s\n%d\n%s\n%s\n%f\n",s1.name,s1.add.dno,s1.add.street,s1.add.city,s1.avg);
   	return 0;
}
