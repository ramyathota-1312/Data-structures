#include<stdio.h>
struct date
{
	int dd;
	int mm;
	int yy;
};
struct age
{
	char name[30];
	struct date dob;
	int tdd;
	int tmm;
	int tyy;
};
int main()
{
	struct age d1={13,12,2006};
	scanf("%d %d %d\n",&d1.tdd,&d1.tmm,&d1.tyy);
	printf("%d-%d-%d",d1.dob.dd,d1.dob.mm,d1.dob.yy);
	printf("%d-%d-%d",d1.tdd,d1.tmm,d1.tyy);
	return 0;
}
