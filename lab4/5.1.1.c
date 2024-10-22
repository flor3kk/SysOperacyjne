#include<stdio.h>

// 5.1.1 i 5.1.2
void printChars(FILE *fp){
    char Str;

    while((Str = fgetc(fp)) != EOF){
        printf("%c", Str);
    }
    printf("\n");
}

// 5.2.1
int countWords1(FILE *fp){
    char ch;
    int count = 0;
    int inside = 0;
    
    while((ch = fgetc(fp)) != EOF){
        if(isspace(ch)){
           inside = 0;
        }
        else if(!inside){
           inside = 1;
           count++;
        }                
    }
    return count;
}

// 5.3
void printWords2(FILE *fp){
    char buffer[256];
    
    while(fgets(buffer, sizeof(buffer), fp)){
        char *word = strtok(buffer, " \t\n");
        while (word != NULL){
            printf("%s\n", word);
            word = strtok(NULL, " \t\n");
        }
    }

}

// 5.4.1
void printHex(FILE *fp){
    char ch;
    int inside = 0;
    
    while((ch = fgetc(fp)) != EOF){
        printf("%02X ", ch);              
    }
}

// 5.4.2
void printChar(FILE *fp){
    char ch;
    
    while((ch = fgetc(fp)) != EOF){
        if(isspace(ch)){
            printf("'\\n' ");
        }
        else{
            printf("'%c' ", ch); 
        }             
    }
}

// 5.4.3
void printLinesHex(FILE *fp){
    char ch;
    
    while((ch = fgetc(fp)) != EOF){
        if(ch == '\n')
            printf("\n");
        else{
            printf("%02X ", ch);              
         }
    }
}

// 5.1.3
void copy(const char * addr1, const char * addr2){
    FILE *source, *dest;
    char ch;

    source = fopen(addr1, "r");
    if (source == NULL) {
        printf("nie mozna otworzyz zrodla: %s\n", addr1);
        return;
    }

    dest = fopen(addr2, "w");
    if (dest == NULL) {
        printf("nie mozna otworzyc celu: %s\n", addr2);
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    fclose(source);
    fclose(dest);
}

// 5.2.2
int countWords2(FILE *fp){
    char ch, prev = ' ';
    int count = 0;
    
    while((ch = fgetc(fp)) != EOF){
        if(!isspace(ch) && isspace(prev)){
           count++;
        }   
        prev = ch;           
    }
    return count;
}


int main() {
    FILE *fp = fopen("C:\\Users\\Florek\\Desktop\\SO2_sem5\\SysOperacyjne\\lab4\\test.txt", "r");
    if (fp == NULL) {
        printf("Nie udalo się otworzyc pliku.\n");
        return 1;
    }
    //printChars(fp);
    //printf("liczba slow = %d", countWords1(fp));
    //printWords2(fp);
    //printHex(fp);
    //printChar(fp);
    //printLinesHex(fp);

    //printf("liczba slow = %d", countWords2(fp));
    const char *source_file = "C:\\Users\\Florek\\Desktop\\SO2_sem5\\SysOperacyjne\\lab4\\test.txt";
    const char *dest_file = "C:\\Users\\Florek\\Desktop\\SO2_sem5\\SysOperacyjne\\lab4\\test2.txt";
    copy(source_file, dest_file);


    fclose(fp);
    return 0;
}