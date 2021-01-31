//
//Given a string in input (dynamically allocated) calculate the reverse string
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

char *inverti(char str[], int lenght){

    char *inversa = calloc(lenght, sizeof(char)); 
    if(!inversa){
        printf("\nErrore");
        exit(-1);
    }

    for(int i = 0; i < lenght; i++){
        inversa[lenght-i-1] = str[i];
    }

    return inversa;
}

int main(){

    printf("Stringa: " );
    char *str;

    do{
        scanf("%s", str);

        if(strlen(str) > MAX)
            printf("\nStringa non valida, reinserire: ");

    }while(strlen(str) > MAX);

    char *s = calloc(strlen(str), sizeof(char)); 
    if(!s){
        printf("\nErrore");
        exit(-1);
    }
    
    strcpy(s, str);

    s = inverti(s, strlen(str));

    printf("\nInversa: %s", s);

    free(s);
    return 0;
}
