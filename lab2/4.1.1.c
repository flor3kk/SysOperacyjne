#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Fraction {    
    int num, den;
};


int isNumber(const char *s){
    
    printf("%s\n", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            printf("'%c' jest cyfra\n", s[i]);
        }
        else{
            printf("'%c' nie jest cyfra\n", s[i]);
        }
    }
}


char *trim(char *s){
    while(isspace(*s)){
        s++;
    }
    char *end = s + strlen(s) - 1;
    while(end > s && isspace(*end)){
        end--;
    }
    *(end + 1) = '\0';
 
    return s;
}


int getOperator(char *operator, const char *s){
    if(s == '/' || s == '*' || s == '+'|| s =='-'){
        return 1;
    }else{
        return 0;
    }
}


int getFraction(struct Fraction *x, const char *s){

    char *lol = strchr(s, '/');
    
    if (lol == NULL) {
       if(isNumber(s)){
           x->num = atoi(s);
           x->den = 1;
           return 1;
       }
    return 0;
    }
    char licznik[100];
    char mianownik[100];
    strncpy(licznik, s, lol - s);
    licznik[lol - s] = '\0';
    
    strcpy(mianownik, lol + 1);
    
    if(isNumber(licznik)&& isNumber(mianownik)){
        x->num = atoi(licznik);
        x->den = atoi(mianownik);
        
        return 1;
    }
    
    return 0;
}


 int main(int argc, char const *argv[]){    
    //  const char *test1 = "123";
    //  const char *test2 = "-123";
    //  const char *test3 = "abc";
    // printf(isNumber(test1));
    // printf(isNumber(test2));
    // printf(isNumber(test3));

// ----------------------------------//

    //   char test1[] = "      Hello world   ";
    //   char test2[] = "Hello world      ";
    //   char test3[] = "Hello      world";
    //   char test4[] = "       ";
      
    //   printf("%s\n", trim(test1));
    //   printf("%s\n", trim(test2));
    //   printf("%s\n", trim(test3));
    //   printf("%s\n", trim(test4));
     
// ----------------------------------//   

// ----------------------------------//     
    // char s = '+--';
    // char operator;
    // printf("%c jest %d", s, getOperator(&operator,s));
    // return 0;
// ----------------------------------//    
    struct Fraction frac;
    const char *s1 = "36/5";
    const char *s2 = "42";

    if (getFraction(&frac, s1)) {
        printf("ulomek: %d/%d\n", frac.num, frac.den);
    } else {
        printf("format zly\n");
    }

    if (getFraction(&frac, s2)) {
        printf("calkowita: %d\n", frac.num);
    } else {
        printf("format zly\n");
    }

     return 0;
 }