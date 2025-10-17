#include<stdio.h>
#include<string.h>
struct student
{
	int rno;
	char name[30];
	float avg;
}s1,s2;
int main()
{
	struct student s3={449,"Ramya",97.5	};
	s2=s3;
	printf("\nEnter Roll.no,name,avg:\n");
	scanf("%d%s%f",&s1.rno,&s1.name,&s1.avg);
	printf("Roll.no\tName\taverage\n");
	printf("%d\t%s\t%f\n",s1.rno,s1.name,s1.avg);
	printf("%d\t%s\t%f\n",s2.rno,s2.name,s2.avg);
	printf("%d\t%s\t%f\n",s3.rno,s3.name,s3.avg);
	return 0;
}
