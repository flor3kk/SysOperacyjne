#include <stdio.h>
#include <math.h>

int licz(int n) {
    if (n == 0)  // no jak jest 0 to jedna cyfra prosta rzecz
        return 1;
    if (n < 0)   // cwaniacy ujemna liczbe wpisali
        n = -n;

    return (int)log10(n) + 1;
}

int main() {
    FILE *file;
    int n;

    file = fopen("liczba.txt", "r"); // odczyt rzecz jasna

    if (file == NULL) {
        printf("nie ma bata na liczba.txt\n");
        return 1;
    }

    fscanf(file, "%d", &n); // zliczamy
    fclose(file);

    printf("liczba cyfr w tej oto pieknej liczbie %d: %d\n", n, licz(n));

    return 0;
}
