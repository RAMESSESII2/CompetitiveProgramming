#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
    struct point *polygon;
    int num;
    printf("Enter the vertices you need: ");
    scanf("%d",&num);
    polygon= (struct point *) malloc( num* sizeof(struct point));
    initializePoly(polygon,num);
    printPoly(polygon, num);
    // Fill in your main function here
}

void initializePoly(struct point *p, int vertices)
{
    int i;
    for(i=0; i<vertices; i++)
    {
        p[i].x=-i;
        p[i].y=i*i;
    }
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

// Write your initializePoly() function here

