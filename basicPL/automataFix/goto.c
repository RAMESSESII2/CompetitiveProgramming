#include<stdio.h>
int main()

{

int i = 1;

while (i <= 6)

    {

         printf( "%d", i );

         if (i > 2) goto here;

         i++;

     }
    here : printf( "PP" );

}

