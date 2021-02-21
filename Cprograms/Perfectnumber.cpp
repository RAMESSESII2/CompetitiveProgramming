#include<stdio.h>
int main()
{
	int a,i,n,sum=0,p=1;
	printf("Provide the number to be checked\n");
	scanf("%d",&n);
	a=n;
	printf("The factors of the number are: ");
	for(i=1; i<a; i++)
	{
		if(n%i==0)
		{
			printf("%d, ",i);
			sum=sum+i;
			p=p*i;
	    }
	}
	if(sum==p)
	{
		printf("The number is a perfect number.\n");
	}
	else
	printf("Not a Perfect no.");
	return 0;
}


