#include<stdio.h>
int main()

{

int a = 10;
void *p = &a;
printf("%u",*p);
int *ptr = p;
printf("%u",*ptr);
return 0;

}
