//Here is the assignment
//https://www.notion.so/simoneguarneri/Tracce-per-Esame-f1a3da71242c4db5a4accb3ca0085c49#733c1a406a9b4909862b7304c7ec7187
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUMDRAGHI 3
#define MAXSTRLEN 20

typedef struct Drago{
    char nome[MAXSTRLEN];
    int vita;
    float dps;
} Drago;

typedef Drago Draghi[NUMDRAGHI];

char* dropN(char* str){
    if(str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';
    return str;
}

void inputDraghi(Draghi draghi){
    
    for(int i = 0; i < NUMDRAGHI; i++){
        
        fflush(stdin);

        printf("\n\nNome: ");
        fgets(draghi[i].nome, 20, stdin);
        strcpy(draghi[i].nome, dropN(draghi[i].nome));

        printf("Vita: ");
        do{
            scanf("%d", &draghi[i].vita);

            if(draghi[i].vita % 1000 != 0)
                printf("\nLa vita deve essere multipla di 1000, reinserirla: ");

        }while(draghi[i].vita % 1000 != 0);

        printf("Dps: ");
        scanf("%f", &draghi[i].dps);
    }
}

int checkVitaDraghi(Draghi draghi, int rimasti){

    for(int i = 0; i < rimasti; i++){
        if(draghi[i].vita <= 0)
            return i;
    }

    return -1;
}

int eliminaDrago(Draghi draghi, int eliminato, int rimasti){

    for(int i = eliminato; i < rimasti-1; i++)
        draghi[i] = draghi[i+1];

    return rimasti-1;
}

void scontroDraghi(Draghi draghi){
    srand(time(NULL));

    int attacca;
    int difende;
    int eliminato;
    int rimasti = NUMDRAGHI;

    while(rimasti > 1){

        attacca = rand() % rimasti;    
        do{
            difende = rand() % rimasti;  
        }while(difende == attacca);
        
        
        draghi[difende].vita -= draghi[attacca].dps;
        printf("\n%s attacca %s, infliggendo %.2f danni, vita rimasta a %s = %d\n", draghi[attacca].nome, draghi[difende].nome, draghi[attacca].dps, draghi[difende].nome, draghi[difende].vita);

        eliminato = checkVitaDraghi(draghi, rimasti);
        if(eliminato != -1)
            rimasti = eliminaDrago(draghi, eliminato, rimasti);

        sleep(1);
    }

    //il drago che vince sarà in posizione 0
}


int main(){

    Draghi draghi;

    FILE* vincitori;
    vincitori = fopen("vincitori.dat", "rb");

    Drago *head = draghi;
    int contaDraghi = -1;

    do{
        fread(head, sizeof(Drago), 1, vincitori);
        head++;
        contaDraghi++;
    }
    while(!feof(vincitori));

    fclose(vincitori);

    if(contaDraghi < 3){

        printf("Inserisci i draghi");
        inputDraghi(draghi);
        vincitori = fopen("vincitori.dat", "ab");
    }
    else{
        printf("\n\nSCONTRO PER IL RE DEI DRAGHI!\n\n");
        vincitori = fopen("vincitori.dat", "wb");
    }
    
    scontroDraghi(draghi);

    printf("\n\nVincitore: %s", draghi[0].nome);

    fwrite(&draghi[0], sizeof(draghi[0]), 1, vincitori);
    fclose(vincitori);
    
    return 0;
}