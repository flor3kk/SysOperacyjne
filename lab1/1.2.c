#include <stdio.h>

int main(){
    char string[100];

    printf("wpisz: ");
    fgets(string, 100, stdin);
    
    //if (stdin == NULL) 
    if (string[0] == '\n'){
        printf("PUSTKA");
    }
    else{
        printf("nie ma pustki, oto zawartosc: %s", string);
    }

    return 0;
}