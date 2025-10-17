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
	struct student s3={449,"Ramya",96.5};
	s1.rno=447;
	strcpy(s1.name,"salomi");
	s1.avg=98.5;
	scanf("%d",&s2.rno);
	scanf("%s",&s2.name);
	scanf("%f",&s2.avg);
	printf("%d\t%s\t%f\n",s1.rno,s1.name,s1.avg);
	printf("%d\t%s\t%f\n",s2.rno,s2.name,s2.avg);
	printf("%d\t%s\t%f\n",s3.rno,s3.name,s3.avg);
	return 0;
}
