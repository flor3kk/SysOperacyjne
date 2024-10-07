#include <stdio.h>

float ciag(int x){
    if (x == 0)
    {
        return 1;
    }
    else if (x == 1)
    {
        return 4;
    }
    else 
        return 2 * ciag(x - 1) + 0.5 * ciag(x - 2);
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
        printf("ciag(%d) = %.2f", numer, ciag(numer));
    }
    
    return 0;
}