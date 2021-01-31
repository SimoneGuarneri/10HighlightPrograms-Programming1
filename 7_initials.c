// Take a varible number of strings of MAXSTRLEN characters in input
// allocate them dynamically and create e new string with the inital letter of 
// each strings, this string should also be allocated dynamically


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 15

void *xmalloc(int size){

    void *p = malloc(size);

    if(!p){
        printf("\nErrore allocazione");
        exit(-1);
    }

    return p;
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

char *iniziali(char **stringhe, int lung){

    char *iniz = xmalloc(lung);
    int lungIniz = 0;

    for(int i = 0; i < lung; i++)
        if(stringhe[i] && strlen(stringhe[i]) > 0)
            iniz[lungIniz++] = stringhe[i][0];
    
    iniz[lungIniz] = '\0';
    return iniz;
}

int main(){

    printf("\nStringhe da inserire: ");
    int dim;
    scanf("%d", &dim);

    char **stringhe = xmalloc(sizeof(char*) * dim); 

    for(int i = 0; i < dim; i++)
        stringhe[i] = inserisciStringa(MAXSTRLEN);

    char *stringaIniziali = iniziali(stringhe, dim);

    printf("\nIniziali: %s", stringaIniziali);
    
    for(int i = 0; i < dim; i++)
        free(stringhe[i]);

    free(stringhe);

    return 0;
}
