#include<stdio.h>

void move(int *(&p), int x){
    p = &x;
    x =10;
}

int main(){
    int x = 100, *p, y = 200;
    p = &x; 
    move(p, y);
    printf("%d\n", (*p));
    return 0;
}
