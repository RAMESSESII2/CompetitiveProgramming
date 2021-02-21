#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
void readDate(struct date *ptr)
{
    scanf("%d",&(*ptr).year);
    scanf("%d",&(*ptr).month);
    scanf("%d",&(*ptr).day);
}

void printDate(struct date dt)
{
    printf("%02d/%02d/%d\n",dt.month,dt.day,dt.year);
}
// Write your readDate() and printDate() functions here
