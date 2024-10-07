#include <stdio.h>

int main(){
    int a;
    float b;
    char c[10];

    
    printf( "a=");
    scanf( "%d", &a);
    printf( "int a= %d\n", a);

    printf( "b=");
    scanf( "%f", &b);
    printf( "int b= %f\n", b);

    printf( "c=");
    scanf( "%9s", &c);
    printf( "char c= %9s\n", c);


    return 0;
}