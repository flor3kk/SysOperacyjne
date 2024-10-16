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


int getOperator(char *op, const char *s) {
    if (strlen(s) == 1 && (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == ':')) {
        *op = *s;
        return 1;
    }
    return 0;
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

char *identity(const char *name, const char *surname){    

     char *result = malloc(strlen(name) + strlen(surname) + 2);   
     strcpy(result, name);   
     strcat(result, " "); 
     strcat(result, surname);
         
     printf("%s", result);
 
}


char *login(const char *name, const char *surname){
    
    char sign = *name;
    char *result = (char*)malloc(33);
    
    sprintf(result, "%c%s", sign, surname);

    return result; 

}


void printFraction(struct Fraction x){
    if (x.den == 0)
    {
        printf("NaN\n");
        return;
    }
    if(x.num == 0){
        printf("0\n");
        return;
    }
    else{   
        printf("%d / %d\n", x.num, x.den);
    }
}

void inputFraction(int *licznik, int *mianownik) {
    while (1) {
        printf("Podaj liczbe w formacie a/b: ");
        if (scanf("%d/%d", licznik, mianownik) == 2 && *mianownik != 0) {
            break;
        } else {
            printf("Niepoprawny format lub mianownik równy zero. Spróbuj ponownie.\n");
            while (getchar() != '\n');
        }
    }
}
/*
a/b + c/d = (a*d)/(b*d) + (c*b)/(d*b) = (a*d + c*b) / (b*d)
*/

struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d + c*b;
    z.den = b*d;
    
    return z;
}

struct Fraction sub(struct Fraction x, struct Fraction y){
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a*d - c*b;
    z.den = b*d;

    return z;

};

struct Fraction mul(struct Fraction x, struct Fraction y){
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a*c;
    z.den = b*d;

    return z;

};

struct Fraction quo(struct Fraction x, struct Fraction y){
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a*d;
    z.den = b*c;

    return z;

};

void main() {

    // do zadan 3.2.2 i 3.2.3
    char *name = "Jan";    
    char *surname = "Kowalski";  

    //char *ident = identity(name, surname);
    //printf("%s\n", ident);

    //char *log = login(name, surname);   
    //printf("%s\n", log);    

    // do zadan 4.1.1
    // const char *test1 = "123";
    // const char *test2 = "-123";
    // const char *test3 = "abc";
    // printf(isNumber(test1));
    // printf(isNumber(test2));
    // printf(isNumber(test3));

    // do zadan 4.1.2
    // char test1[] = "      Hello world   ";
    // char test2[] = "Hello world      ";
    // char test3[] = "Hello      world";
    // char test4[] = "       ";
      
    // printf("%s\n", trim(test1));
    // printf("%s\n", trim(test2));
    // printf("%s\n", trim(test3));
    // printf("%s\n", trim(test4));

    struct Fraction x = {2, 5};
    struct Fraction y = {1, 5};
    
    struct Fraction z = sum(x, y);

    printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den); 

    struct Fraction b = sub(x, y);  

    printf("%d/%d - %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, b.num, b.den); 

    struct Fraction c = mul(x, y);  

    printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, c.num, c.den);


    struct Fraction d = quo(x, y);  

    printf("%d/%d / %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, d.num, d.den);


    // do zadan 4.1.3
    // const char *tests[] = {"+", "-", "abc", "*", ":", "/", "xyz"};
    // int n = sizeof(tests) / sizeof(tests[0]);
    // char op;

    // for (int i = 0; i < n; i++) {
    //     if (getOperator(&op, tests[i])) {
    //         printf("Test %d: %s -> Operator: %c\n", i + 1, tests[i], op);
    //     } else {
    //         printf("Test %d: %s -> Niepoprawny operator\n", i + 1, tests[i]);
    //     }
    // }


    // do zadan 4.1.4
    // struct Fraction frac;
    // const char *s1 = "36/5";
    // const char *s2 = "42";

    // if (getFraction(&frac, s1)){
    //     printf("ulamek: %d/%d\n", frac.num, frac.den);
    // }
    // else{
    //     printf("fomrat zly\n");
    // }

    // if(getFraction(&frac, s2)){
    //     printf("liczba calkowita: %d\n", frac.num);
    // }
    // else{
    //     printf("foramt zly\n");
    // }

    // do zadan 4.1.5
    int m;
    int n;
    int o;
    int p;
    char ope;

    inputFraction(&m, &n);
    printf("%d/%d\n", m, n);

    inputFraction(&o, &p);
    printf("%d/%d\n", o, p);

    printf("podaj znak: ");
    scanf(" %c", &ope);

    printf("%c\n", ope);

    struct Fraction x1 = {m, n};
    struct Fraction x2 = {o, p};
    struct Fraction res;
    switch(ope){
        case '+':
            res = sum(x1, x2);
            break;
        case '-':
            res = sub(x1, x2);
            break;
        case '*':
            res = mul(x1, x2);
            break;
        case '/':
        case ':':
            res = quo(x1, x2);
            break;
        default:
            printf("nieznany operator");
    }
    
    printf("%d/%d %c %d/%d = %d/%d\n", x1.num, x1.den, ope, x2.num, x2.den, res.num, res.den);


    // do zadania 3.1.2
    // printFraction((struct Fraction){2,0});  
    // printFraction((struct Fraction){0,2});  
    // printFraction((struct Fraction){2,4});  
}


