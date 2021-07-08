#include<stdio.h>

int main(){
    const int x = 5;
    void *p = &x;
    int *pointer = p;
    *pointer = 10;
    printf("%d", x);
}
