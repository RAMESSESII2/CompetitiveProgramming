#include <stdio.h>
#include <stdlib.h>

typedef struct student {
      char name[50];
      int age;
      student *next;
};

student *createStudent(char studentName[], int studentAge);

// Write other function prototypes here (if any)

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}

// Write your createStudent function here (and any other functions you see fit)
student *createStudent(char studentName[], int studentAge)
{
    student *ptr;
    ptr=(student *)malloc(sizeof(student));
    ptr->name[0]=studentName[0];
    ptr->age=studentAge;
    ptr->next=NULL;
    return(ptr);
    
}
