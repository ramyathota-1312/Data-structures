#include<stdio.h>
struct date
{
	int dd;
	int mm;
	int yy;
};
struct student
{
	char name[32];
	struct date dob;
	float avg;
};
int main()
{
	struct student s1={"Ramya",{13,12,2006},56.5};
	printf("Memory created=%d\n",sizeof(s1));
	printf("%s\t%d-%d-%d\t%f\n",s1.name,s1.dob.dd,s1.dob.mm,s1.dob.yy,s1.avg);
	return 0;
}
