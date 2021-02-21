#include<stdio.h>
int main()
{
	int a[100],n,i,first, last, mid, search;
	printf("Provide no.of elements:");
	scanf("%d",&n);
	printf("Enter elemnets of the array:\n");
	for(i=0; i<n; i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&search);
	first=0;
	last=n-1;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(a[mid]<search)
		{
			first=mid+1;
		}
		else if(a[mid]=search)
		{
			printf("Element is found");	
			break;
		}
		else
		last=mid-1;
	}
	if(first>last)	
	{
		printf("Element is not found");
	}
}
