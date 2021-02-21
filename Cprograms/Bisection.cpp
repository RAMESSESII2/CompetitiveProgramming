#include<stdio.h>
float function(float x)
{
	return (x*x*x-x*x+2);
}
int main()
{
	int a,b;
	printf("Provide the range in which x lies:");
	scanf("%d%d",&a,&b);
	if(function(a)*function(b)<0)
	{
	while(b-a>=0.01)
	{
		float c=(a+b)/2.0;
		if(function(c)==0)
		{
			printf("The root is %f",c);
			break;
		}
		else if(function(a)*function(c)<0)
		{
			b=c;
		}
		else 
		a=c;		
	}
}
	else
	 printf("Invalid expresiion for Bisection Method");
	return 0;
}
