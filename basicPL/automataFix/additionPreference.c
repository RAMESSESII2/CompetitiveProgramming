#include<stdio.h>

int main(void)

{
int a = 13;
a = a++ + a++;

int b = 13;
b = b++ + ++b;

int c = 13;
c = ++c + c++;

int d = 13;
d = ++d + ++d;

printf("%d %d %d %d", a, b, c, d);
}
