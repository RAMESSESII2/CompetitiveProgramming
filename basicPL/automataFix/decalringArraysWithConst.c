#include <stdio.h>
#define s 4
void main()

{
    const int SIZE = 5;
    int expr;
    double value[SIZE] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
    expr=1|2|3|4;
    printf ( "%f  %d", value[expr], expr );
}
