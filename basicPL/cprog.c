#include<stdio.h>
#include<string.h>

char *vow = "aeiouy", c, ch;
int main(){
    int i =0, n;
    for( scanf("%i", &n), getchar(); i < n; ){
        putc(ch = getchar(), stdout); i++;
        if( strchr(vow, ch) ){
            while( ++i && strchr(vow, c = getchar()) );
            putc(c, stdout);
        }
    }
}


/* int a, b, c = 0; */
/* void prtFun(void); */
/* int main(){ */
/*     static int a = 1; */
/*     prtFun(); */
/* } */

/* void prtFun(void){ */
/*     static int a = 2; */
/*     int b = 1; */
/*     a += ++b; */
/*     printf( "%d %d", a, b ); */
/* } */
