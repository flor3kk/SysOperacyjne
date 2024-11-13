#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int wariacje1(){
    // a - z = 26, A - Z = 26, 0 - 9 = 10, . / 
    int x = 64;
    return x * x;
}


void set(char salt[2]){
    char znaki[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    salt[0] = znaki[rand() % 64];
    salt[1] = znaki[rand() % 64];
     
}


void errnoExample(){
    FILE *file = fopen("plik.txt", "r");
    if (file == NULL){
        printf("error opening file %s\n", strerror(errno));
    }
}


int main() {
    srand(time(NULL));
    
    // 8.2.4
    char salt[2];
    set(salt);
    printf("salt: %c%c \n", salt[0], salt[1]);
    
    // 8.2.2
	printf("wariacje 1: %d\n", wariacje1());
    
    // 8.2.5
    errnoExample();
    
    
    return 0;
}