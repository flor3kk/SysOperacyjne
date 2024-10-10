#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

struct Fraction {
    int num, den;
};

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
    struct Fraction x = {2, 3};
    struct Fraction y = {1, 4};
    
    struct Fraction z = sum(x, y);

    printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, z.num, z.den); 

    struct Fraction b = sub(x, y);  

    printf("%d/%d - %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, b.num, b.den); 

    struct Fraction c = mul(x, y);  

    printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, c.num, c.den);


    struct Fraction d = quo(x, y);  

    printf("%d/%d / %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, d.num, d.den);
}
