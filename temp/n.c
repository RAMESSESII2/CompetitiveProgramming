#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main ()
{
char *testhack = NULL;

testhack = malloc(8);

strcpy(testhack, "Hackathons"); 

printf("testhack=%s\n", testhack); 

testhack = realloc(testhack, 15); 
printf("testhacks = %s\n", testhack);

free(testhack); 
return 0;
}
