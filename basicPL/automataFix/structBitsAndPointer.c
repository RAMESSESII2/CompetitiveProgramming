#include<stdio.h>

struct marks{
    int p : 3;// it describes how many bits the particular field uses
    int  c: 4;
    int m : 10;
};

void main(){
    struct marks s= {2, -6, 5};
    printf("%d %d %d\n",s.p, s.c, s.m);
    int *p, *q;
    /* p = 1000; */
    /* q = 1000; */
    p = (int *)1000;
    q = (int *)2000;
    printf("%d ",q- p);
    printf("\n%d %d",p, q);
}
