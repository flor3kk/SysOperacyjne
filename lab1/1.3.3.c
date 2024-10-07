#include <stdio.h>

int fibo3(int x) {
    if (x == 0 || x == 1)
        return 1;

    int r0 = 1;  
    int r1 = 1;  
    int pom;     

    for (int i = 2; i <= x; i++) {
        pom = r0;
        r0 = r1;
        r1 = r0 + pom;
    }

    return r1;  
}

int main() {

    int numer;
    printf("podaj wyraz ciagu: ");
    scanf("%d", &numer);

    if (numer < 0) {
        printf("blad\n");
    } else {
        printf("ciag(%d) = %d\n", numer, fibo3(numer));
    }

    return 0;
}
