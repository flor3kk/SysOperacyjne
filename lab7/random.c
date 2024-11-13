#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int losuj(int a, int b){
    int r = rand(a) % (b - a + 1) + a;

    return r;
}

int main() {
    srand(time(NULL));
    
    int a;
    int b;
    
    printf("podaj liczbe a: ");
    scanf("%d: ", &a);
    
    printf("podaj liczbe b: ");
    scanf("%d: ", &b);

	if (b < a){
        printf("podany przedzial jest zly\n");
        return 0;
    }
    
	printf("wylosowana liczba: %d", losuj(a,b));

    return 0;
}