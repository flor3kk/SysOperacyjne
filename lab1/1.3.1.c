#include <stdio.h>

int fibo(int x){
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else 
        return fibo(x - 1) + fibo(x - 2);
}

int main(){

    int numer;
    printf("podaj wyraz ciagu: ");
    scanf("%d", &numer);

    if (numer < 0)
    {
        printf("blad");
    }
    else
    {
        printf("fibo(%d) = %d", numer, fibo(numer));
    }
    
    return 0;
}