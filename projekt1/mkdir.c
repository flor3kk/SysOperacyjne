#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	char folderName[256];
	
	printf("podaj nazwe: ");
	scanf("%255s", folderName); 

    if (mkdir(folderName) == 0) {
        printf("utworzylem folder %s\n", folderName);
    } else {
        printf("nie udalo sie utworzyc\n");
    }

    return 0;
}
