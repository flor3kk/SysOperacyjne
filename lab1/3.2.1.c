#include <stdio.h>
 
int indexOf(const char *str, int c) {
    const char *ptr = str;
    int index = 0;        
 
    while (*ptr != '\0') {
        if (*ptr == c) {
            return index;
        }
        ptr++;    
        index++;  
    }
   
    return -1;
}
 
// int indexOf(const char *str, int c) { // od Wojtowicza, pierwsza wersja
//     char* ptr = strchr(str, c);

//     if (ptr == NULL) return -1;

//     int index = ptr - str;

//     return index;
// }


// int indexOf(const char *str, int c) { // od Wojtowicza, druga wersja
//     const char *ptr = str;
//     while (*ptr != '\0') {
//         if (*ptr == c) {
//             return ptr - str;
//         }
//         ptr++;
//     }
//     return -1;
// }

int main() {
    const char *str = "99$ hello";
    char c = 'h';
   
    printf(str);
    printf("\n");

    int index = indexOf(str, c);
    if (index != -1) {
        printf("Znak '%c' jest tu: %d\n", c, index);
    } else {
        printf("Znak '%c' nie ma ;(\n", c);
    }
 
    c = '9';
    index = indexOf(str, c);
    if (index != -1) {
        printf("Znak '%c' jest tu: %d\n", c, index);
    } else {
        printf("Znak '%c' nie ma :(\n", c);
    }
 

    return 0;
}