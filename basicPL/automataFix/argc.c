#include<stdio.h>
main(int argc, char *argv[])

{

    int i, j = 0;

    for (i = 0; i < argc ; i++){
            printf ("%d\n", i);
            printf ("%c\n", argv[i]);
           j = j + atoi ( argv[i]);
    }

    printf ("%d", j);

}
