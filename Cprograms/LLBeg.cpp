#include<stdio.h>
struct point
{
    char x[50];
    int y;
    struct point *next;
};
void printll(struct point *);
int main()
{
    struct point *start;
    struct point p={"fcgc",12,NULL};
    struct point q={"fghgc",3,NULL};
    struct point r={"gcgfc",35,NULL};
    start=&p;
    p.next=&q;
    q.next=&r;
    printll(start);
    return 0;
}
void printll(struct point *start)
{
    struct point *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%s %d\n",ptr->x,ptr->y);
        ptr=ptr->next;
    }
}
