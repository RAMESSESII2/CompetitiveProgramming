#include<stdio.h>
struct point{
	int x;
	int y;
};
void scancord(struct point *);
void printcord(struct point );
int main()
{
	struct point z;
	scancord(&z);
	printcord(z);
	return 0;
}
void scancord(struct point *p)
{
	printf("Enter the coordinates:\n");
	printf("x:");
	scanf("%d",&(p->x));
	printf("y:");
	scanf("%d",&(p->y));
}
void printcord(struct point p)
{
	printf("The coordinates are:\n");
	printf("x,y=(%d,%d)",p.x,p.y);
	
}
