//
//Given n strings (nStringhe) take them in input, allocate them dynamically and concatenate them in one onlystring
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strConcat(char *s1, char *s2){

    char *s3 = calloc(strlen(s1) + strlen(s2), sizeof(char));

    if(!s3){
        printf("\nErrore allocazione");
        exit(-1);
    }

    strcpy(s3, s1);
    strcat(s3, s2);

    free(s1);
    return s3;
}

char* inserisciStringa(int maxDim){
    
    char *s = malloc(maxDim);
    do{ 

        scanf("%s", s);

        if(strlen(s) > maxDim)
            printf("\nStringa troppo lunga, reinserirla: ");
        
    }while(strlen(s) > maxDim);

    return  s;
}

int inserisciDim(){

    int dim;

    do{

        scanf("%d", &dim);
        if(dim <= 0)
            printf("\nStringa inserita non valida, reinserirla: ");

    }while(dim <= 0);

    return dim;
}

char* newStringa(){

    printf("Dimensione stringa: ");
    int dim = inserisciDim();

    char *s = malloc(dim+1); //+1 per \0
    if(!s){
        printf("\nErrore di allocazione\n");
        exit(-1);
    }

    printf("Stringa: ");
    s = inserisciStringa(dim);

    return s;
}

int main(){

    printf("Numero di Stringhe: ");
    int nStringhe = inserisciDim();

    char *parola1 = newStringa();
    char *parola2;

    for(int i = 1; i < nStringhe; i++){

        parola2 = newStringa();
        parola1 = strConcat(parola1, parola2);
        
    }
    
    printf("\nConcatenazione: %s", parola1);

    free(parola1);
    free(parola2);
}