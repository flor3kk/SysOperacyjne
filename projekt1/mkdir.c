#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *folderName = "katalog_projekt";  

    if (mkdir(folderName) == 0) {
        printf("Katalog '%s' został pomyślnie utworzony.\n", folderName);
    } else {
        printf("Błąd podczas tworzenia katalogu");
    }

    return 0;
}
