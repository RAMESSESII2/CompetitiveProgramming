#include<stdio.h>
int main()
{
	int i;
	char a[4]={'s','a','t','y'};
	for(i=0; i<4; i++)
	{
		if(a[i]>='a' && a[i]<='z')
		{
			printf("\na[%d]= %c\n",i,a[i]-('a'-'A'));	
		}
		else 
		printf("a[%d]= %c",i,a[i]);
	}
	return 0;
}
