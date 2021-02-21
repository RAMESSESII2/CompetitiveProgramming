#include<stdio.h>
int main()
{
	int n, i;
	float avg, dev, sum=0;
	float list[100];
	printf("Enter the numbers you want to average: ");
	scanf("%d",&n);
	printf("Provide the numbers-\n");
	for(i=0; i<n; ++i)
	{
		printf("list[%d]=", i+1);
		scanf("%f", &list[i]);
		sum+= list[i];
	}
	avg=sum/n;
	printf("The average is %.2f.\n\n", avg);
	for(i=0; i<n; ++i)
	{
		dev=list[i]-avg;
		printf("list[%d]=%.2f\n Deviation=%.2f\n", i+1, list[i], dev);
	}
	return 0;
}

