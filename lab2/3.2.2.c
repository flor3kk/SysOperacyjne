#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    // char *result = malloc(strlen(name) + strlen(surname) + 2);

    // result[0] = name[0];
    // result[1] = '\0';    
    // strcat(result, surname);
 
    // return result; 
}
         
 int main(int argc, char const *argv[]){    
     char *name = "Jan";    
     char *surname = "Kowalski";    

     //char *id = identity(name, surname);    
     //printf("Wynik: %s\n", id);    
     
     char *log = login(name, surname);   
     printf("%s\n", log);    
     
     return 0;
 }