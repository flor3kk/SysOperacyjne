#include <stdio.h>

int main() {
    double value;

    printf("Podaj wartosc typu double: ");
    scanf("%lf", &value);
    printf("Odczytana wartosc: %.8lf\n", value);
    
    return 0;
}