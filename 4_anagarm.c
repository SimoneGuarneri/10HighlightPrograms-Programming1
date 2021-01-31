//
//Find if two dynamically allocated strings are anagrams
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

char* sort(char *p){

    char *sortedP = p;

    for(int i = 0; sortedP[i]; i++){
        sortedP[i] = tolower(sortedP[i]);
    }
    
    int length = strlen(p);   

    for(int i = 0; i < length; i++){
        
        for(int j = i+1; j < length; j++){
            
            if(sortedP[i] > sortedP[j]){
                char t =  sortedP[i];
                sortedP[i] = sortedP[j];    
                sortedP[j] = t; 
            }
        }
    }

    return sortedP;
}

int isAnagramma(char *p1, char *p2){

    if(strlen(p1) != strlen(p2))
        return 0;
    
    char *p1Sorted = sort(p1);
    char *p2Sorted = sort(p2);

    int length = strlen(p1);

    return strcmp(p1Sorted, p2Sorted) == 0; 
}

char* newStringa(){

    char x[MAX];

    do{

        scanf("%s", x);

        if(strlen(x) > MAX)
            printf("Lunghezza non valida, reinserire: ");

    }while(strlen(x) > MAX);

    char *s = malloc(strlen(x)+1);
    if(!s){
        printf("\nErrore di allocazione\n");
        exit(-1);
    }

    strcpy(s, x);
    return s;
}

int main(){

    printf("Prima Parola: ");
    char *parola1 = newStringa();

    
    printf("Seconda Parola: ");
    char *parola2 = newStringa();


    if(isAnagramma(parola1, parola2))
        printf("\nSono anagrammi");
    else 
        printf("\nNon sono anagrammi");

    free(parola1);
    free(parola2);
}