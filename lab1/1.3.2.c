#include <stdio.h>

int fibo2(int x) {
    if (x == 0 || x == 1)
        return 1;

    int r0 = 1;  
    int r1 = 1;  
    int r2;      

    for (int i = 2; i <= x; i++) {
        r2 = r0 + r1;  // aktualna wartość
        r0 = r1;       // przesuniecie 
        r1 = r2;      
    }

    return r2;  
}

int main() {

    int numer;
    printf("podaj wyraz ciagu: ");
    scanf("%d", &numer);

    if (numer < 0) {
        printf("blad\n");
    } else {
        printf("ciag(%d) = %d\n", numer, fibo2(numer));
    }

    return 0;
}
