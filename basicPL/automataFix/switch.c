#include <stdio.h>
#define s 6
enum state{fi=1, sec, th};

int main()
{
    int a = 1, b = 1;
    switch(a){
        case sec: printf("Sometin ");
                break;
        case fi: printf("Someting ");
        default: printf("akjdk ");
    }
    //the expression provided in the switch should result in a constant value otherwise not valid.
    //a case statement is always followed by constant value not a variable.
    //duplicates are not allowed.
    /* switch (a) */
    /* { */
    /* case a*b: */
    /*     printf("yes "); */
    /* case a-b: */
    /*     printf("non"); */
    /*     break; */
    /* } */
}
