#include<stdio.h>
struct student
{
	int rno;
	int T,H,E,M;
	float tot,avg;
};
int main()
{
	struct student std[100];
	int n,i;
	printf("Enter no.of students:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Roll.no and marks of four subjects:\n");
		scanf("%d%d%d%d%d",&std[i].rno,&std[i].T,&std[i].H,&std[i].E,&std[i].M);
	}
	 printf("Roll.no\tTelugu\tHindi\tEnglish\tMaths\tTotal\tAverage\n");
	for(i=0;i<n;i++)
	{
	    std[i].tot=std[i].T+std[i].H+std[i].E+std[i].M;
	    std[i].avg=std[i].tot/4.0;
	    printf("%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",std[i].rno,std[i].T,std[i].H,std[i].E,std[i].M,std[i].tot,std[i].avg);
	}
	return 0;
}
