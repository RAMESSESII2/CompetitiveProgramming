#include<stdio.h>
struct point {
    int x;
    int y;
    struct point *next;
};
void printPoints(struct point *);
struct point *append(struct point *, struct point *);
int main()
{
    struct point *start, *end;
    struct point p={23,-1, NULL};
    struct point q={23, -12, NULL};
    struct point r={65, 12, NULL};
    start=end=&p;
    end=append(end, &q);
    end=append(end, &r);
    printPoints(start);
    return 0;
}

void printPoints(struct point *start)
{
    struct point *pt;
    pt=start;
    while(pt!=NULL)
    {
        printf("(%d,%d)",pt->x,pt->y);
        pt=pt->next;
    }
}

struct point *append(struct point *end, struct point *pt)
{
    end->next=pt;
    return(end->next);
}
