#include "protos.h"

char* dropN(char* str){
    if(str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';
    return str;
}

int sceltaPvp(){

    printf("\nScegli la modalita'\n");
    printf("1) PvE");
    printf("2) Pvp");

    int scelta;
    do{

        scanf("%d", &scelta);
        if(scelta != 1 && scelta != 2)
            printf("\nModalita' non valida, reinserirla: ");

    }while(scelta != 1 && scelta != 2);

    return scelta-1;
}

Mossa inputMossa(){

    Mossa newMossa;

    fflush(stdin);

    printf("Nome: ");
    fgets(newMossa.nome, MAXSTRLEN, stdin);
    strcpy(newMossa.nome, dropN(newMossa.nome));

    printf("Danno: ");
    scanf("%f", &newMossa.danno);

    return newMossa;
}

Pokemon inputPokemon(){

    Pokemon newPokemon;

    fflush(stdin);

    printf("Nome: ");
    fgets(newPokemon.nome, MAXSTRLEN, stdin);

    strcpy(newPokemon.nome, dropN(newPokemon.nome));

    printf("Vita: ");
    scanf("%d", &newPokemon.vita);

    printf("\nInserisci Mosse");
    printf("\nMossa1 \n");
    newPokemon.mossa1 = inputMossa();
    printf("\nMossa2 \n");
    newPokemon.mossa2 = inputMossa();

    return newPokemon;
}

//puntatori per ottimizzazione
int battleEnd(Pokemon *p1, Pokemon *p2){
    if(p1->vita <= 0)
        return 2;
    if(p2->vita <= 0)
        return 1;
    return 0;
}

//puntatori per ottimizzare
Mossa scegliMossaPlayer(Pokemon *p){

    printf("\nScegli la Mossa da usare: ");
    printf("\n1) %s", p->mossa1.nome);
    printf("\n2) %s\n-> ", p->mossa2.nome);

    int scelta;
    do{

        scanf("%d", &scelta);
        if(scelta != 1 && scelta != 2)
            printf("\nMossa non valida, reinserirla: ");

    }while(scelta != 1 && scelta != 2);
    
    return scelta == 1 ? p->mossa1 : p->mossa2;
}

//puntatori per ottimizzare
Mossa scegliMossaPc(Pokemon *p){

    srand(time(NULL));
    int scelta = rand() % 2;

    return scelta == 0 ? p->mossa1 : p->mossa2;
}

int combattimentoPvE(Pokemon p1, Pokemon p2){

    int turno = 1;
    int battagliaFinita = battleEnd(&p1, &p2);  //0: entrambi vivi
    Mossa mossaScelta;

    while(!battagliaFinita){
        
        //player
        if(turno == 1){
            mossaScelta = scegliMossaPlayer(&p1);

            p2.vita -= (int)mossaScelta.danno;
            printf("\n%s usa %s su %s, infligendo %.2f danni, vita rimasta a %s: %d", 
            p1.nome, mossaScelta.nome, p2.nome, mossaScelta.danno, p2.nome, p2.vita);
            
            turno = 2;
        }   
        //pc
        else{

            sleep(1);

            mossaScelta = scegliMossaPc(&p2);

            p1.vita -= (int)mossaScelta.danno;
            printf("\n%s usa %s su %s, infligendo %.2f danni, vita rimasta a %s: %d",
            p2.nome, mossaScelta.nome, p1.nome, mossaScelta.danno, p1.nome, p1.vita);
            
            turno = 1;
        }

        battagliaFinita = battleEnd(&p1, &p2);
    }

    return battagliaFinita == 1 ? 1 : 2;
}

int combattimentoPvP(Pokemon p1, Pokemon p2){

    int turno = 1;
    int battagliaFinita = battleEnd(&p1, &p2);  //0: entrambi vivi
    Mossa mossaScelta;

    while(!battagliaFinita){
        
        //player
        if(turno == 1){
            mossaScelta = scegliMossaPlayer(&p1);

            p2.vita -= (int)mossaScelta.danno;
            printf("\n%s usa %s su %s, infligendo %.2f danni, vita rimasta a %s: %d", 
            p1.nome, mossaScelta.nome, p2.nome, mossaScelta.danno, p2.nome, p2.vita);
            
            turno = 2;
        }   
        //pc
        else{

            mossaScelta = scegliMossaPlayer(&p1);

            p2.vita -= (int)mossaScelta.danno;
            printf("\n%s usa %s su %s, infligendo %.2f danni, vita rimasta a %s: %d", 
            p1.nome, mossaScelta.nome, p2.nome, mossaScelta.danno, p2.nome, p2.vita);
            
            turno = 2;
        }

        battagliaFinita = battleEnd(&p1, &p2);
    }

    return battagliaFinita == 1 ? 1 : 2;
}