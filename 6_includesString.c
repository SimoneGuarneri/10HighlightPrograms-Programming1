//
//Given STRNUM strings in input and a sub-string to find (daCercare), create a dynamicakky allocated array of strings which contain the sub-string
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRNUM 5
#define MAXSTRLEN 15

void *xmalloc(size_t size){

    void *p = malloc(size);

    if(!p){
        fprintf(stderr, "malloc(%lu) failed. Exiting.\n", size);
        exit(-1);
    }

    return p;
}

int contieneStringa(char *stringa,  char *daContenere){

    int lungString = strlen(stringa);
    int lungDaContenere = strlen(daContenere);

    if(lungString < lungDaContenere)
        return 0;

    int letteraControllata = 0; //lettera di daContenere che sto controllando

    for(int i = 0; i < lungString; i++){

        if(stringa[i] == daContenere[letteraControllata]){         
            letteraControllata++;
            if(letteraControllata == lungDaContenere)
                return 1;
        }
        else{
            letteraControllata = 0;
        }
    }
    return 0;

}

char **sottoElenco(char *v[], int n, char *daContenere){

    char **risultato = xmalloc(n * sizeof(char*));
    int lrisultato = 0;

    for(int i = 0; i < n; i++){

        if(contieneStringa(v[i], daContenere)){
            risultato[lrisultato] = xmalloc(strlen(v[i])+1);
            strcpy(risultato[lrisultato], v[i]);
            lrisultato++;
        }
    }

    risultato = realloc(risultato, lrisultato*sizeof(char*));
    
    return risultato;
}

char *dropN(char *s){

    if(s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
    return s;
}

char *inserisciStringa(int max){

    char *sIn = xmalloc(max);
    do{ 
        fflush(stdin);
        fgets(sIn, max, stdin);

        if(strlen(sIn) > max-1)
            printf("\nStringa troppo lunga, reinserirla: ");
        
    }while(strlen(sIn) > max-1);


    char *sOut = xmalloc(sizeof(char) * (strlen(sIn)-1));
    strcpy(sOut, sIn);
    sOut = dropN(sOut);

    free(sIn);
    fflush(stdin);

    return sOut;  
}

int main(){

    char *stringhe[STRNUM];
    for(int i = 0; i < STRNUM; i++){
        printf("Stringa: ");
        stringhe[i] = inserisciStringa(MAXSTRLEN);
    }

    printf("\nStringa da cercare: ");
    char *daContenere;
    daContenere = inserisciStringa(MAXSTRLEN);

    char **risultato = sottoElenco(stringhe, STRNUM, daContenere);
    
    int i = 0;
    while(risultato[i]){
        printf("\n%s", risultato[i]);
        i++;
    }
    i = 0;
    while(risultato[i]){
        free(risultato[i]);
        i++;
    }
    i = 0;
        while(stringhe[i]){
        free(stringhe[i]);
        i++;
    }

    free(daContenere);
    free(risultato);
    return 0;
}