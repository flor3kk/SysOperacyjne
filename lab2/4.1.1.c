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

 int main(int argc, char const *argv[]){    
//     const char *test1 = "123";
//     const char *test2 = "-123";
//     const char *test3 = "abc";
//
//     printf(isNumber(test1));
//     printf(isNumber(test2));
//     printf(isNumber(test3));

// ----------------------------------//

//       char test1[] = "      Hello world   ";
//       char test2[] = "Hello world      ";
//       char test3[] = "Hello      world";
//       char test4[] = "       ";
//       
//       printf("%s\n", trim(test1));
//       printf("%s\n", trim(test2));
//       printf("%s\n", trim(test3));
//       printf("%s\n", trim(test4));
     
// ----------------------------------//   
     
    char s = '/';
    char operator;
    printf("%c jest %d", s, getOperator(&operator,s));
    return 0;
     
     return 0;
 }