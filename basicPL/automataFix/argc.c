#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{

    int i, j = 0;
    printf("%d\n", argc);
    for (i = 0; i < argc ; i++){
            /* printf ("%d\n", i); */
            printf ("%s\n", argv[i]);
           /* j = j + atoi ( argv[i]); */
    }

    printf ("%d", j);

}
