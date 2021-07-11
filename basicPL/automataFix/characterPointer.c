#include<stdio.h>
int main(){
    char *str = "hello";
    while( printf("%s", str) ) str++;
}
