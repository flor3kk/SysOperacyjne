#include <stdio.h>

int main(){
    char string[20];

    printf("podaj ciag znakow: ");
    fgets(string, sizeof(string), stdin); // ZMIENNA, MAX LICZBA ZNAKOW BUFORA, STRUMIEN
    printf("oto podany ciag: %s", string);

    return 0;
}