#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int x;
	student *next;
}student;
student *createdig(int dig);
student *append(student *end, student *numberptr);
void print(student *start);
void freenumber(student *start);
student *readNumber();
student *insertatfront(student *start, student *newptr);
student *reversenumber(student *start);
student *sortedcopy(student *start);
student *insertintosorted(student *start, student *newdig);

int main(void)
{
	student *start, *backwards, *sorted;
	printf("Enter numberss: ");
	start=readNumber();
	print(start);
	backwards=reversenumber(start);
	print(backwards);
	sorted=sortedcopy(start);
	print(sorted);
	freenumber(start);
	freenumber(backwards);	
	freenumber(sorted);
	return 0;
}

student *reversenumber(student *start)
{
	student *ptr=start;
	student *bstart=NULL;
	student *newdigit;
	
	if(start!=NULL)
	{
		bstart=createdig(start->x);
		ptr=ptr->next;
	}
	while(ptr!=NULL)
	{
		newdigit=createdig(ptr->x);
		bstart=insertatfront(bstart, newdigit);
		ptr=ptr->next;
	}
	return(bstart);
}

student *insertatfront(student *start, student *newptr)
{
	newptr->next=start;
	return(newptr);
}


student *readNumber()
{
	char c;
	int d;
	student *start, *end, *newptr;
	start=NULL;
	scanf("%c",&c);
	while(c!='\n')
	{
		d=c-48;
		newptr=createdig(d);
		if(start==NULL)
		{
			start=newptr;
			end=start;	
		}	
		else
		{
			end=append(end, newptr);
		}
		scanf("%c",&c);
	}
	return(start);	
}

student *createdig(int dig)
{
	student *stdptr;
	stdptr=(student *)malloc(sizeof(student));
	stdptr->x=dig;
	stdptr->next=NULL;
	return(stdptr);
}

student *sortedcopy(student *start)
{	
	student *ptr=start;
	student *sortedstart=NULL;
	student *newdig;
	if(start!=NULL)
	{
		sortedstart=createdig(start->x);
		ptr=ptr->next;
	}
	while(ptr!=NULL)
	{
		newdig=createdig(ptr->x);
		sortedstart=insertintosorted(sortedstart, newdig);
		ptr=ptr->next;
	}
	return(sortedstart);
}

student *insertintosorted(student *start, student *newdig)
{
	student *ptr=start;
	student *prev=NULL;
	while((ptr!=NULL) && (ptr->x<newdig->x))
	{
		prev=ptr;
		ptr=ptr->next;
	}
	if(prev==NULL)
	{
		start=insertatfront(start, newdig);
	}
	else{
		prev->next=newdig;
		newdig->next=ptr;
	}
	return(start);
}




student *append(student *end, student *numberptr)
{
	end->next=numberptr;
	end=numberptr;
	return(end);
}
void print(student *start)
{
	student *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d",ptr->x);
		ptr=ptr->next;
	}
	printf("\n");
}

void freenumber(student *start)
{
	student *ptr,*temp;
	ptr=start;
	while(ptr!=NULL)
	{
		temp=ptr->next;
		free(ptr);
		ptr=temp;
	}	
}
