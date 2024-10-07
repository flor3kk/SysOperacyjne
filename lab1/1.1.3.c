#include <stdio.h>

int main(){
    char string[20];

    printf("podaj ciag znakow: ");
    scanf("%[^\n]", string);
    printf("oto podany ciag: %s", string);

    return 0;
}