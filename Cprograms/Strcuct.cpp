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
    printf("Enter the year: \n");
    scanf("%d",&(*ptr).year);
   printf("Enter the month: \n");
    scanf("%d",&(*ptr).month);
    printf("Enter the day: \n");
    scanf("%d",&(*ptr).day);
}

void printDate(struct date dt)
{
    printf("Date : %02d/%02d/%d\n",dt.month,dt.day,dt.year);
}
