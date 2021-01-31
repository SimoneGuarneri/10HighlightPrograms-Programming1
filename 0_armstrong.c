//
// Find which one of the LUNG numbers in input is an Armstrong Number
//

#include <stdio.h>
#define LUNG 3

int potenza(int base, int esponente){
    int risultato = 1;

    for(int i = 0; i < esponente; i++)
        risultato *= base;

    return risultato;
}

int separaCifre(int num, int numSeparato[]){
    int c = 0;

    while(num > 0){
        numSeparato[c] = num % 10;
        num /= 10;
        c++;
    }
    
    return c;
}

int isArmstrong(int numSeparato[], int lungNumSeparato, int num){

    int sommaPotenze = 0;

    for(int i = 0; i < lungNumSeparato; i++)
        sommaPotenze += potenza(numSeparato[i], lungNumSeparato);
    
    return sommaPotenze == num;
}


int main(){

    printf("Inserisci %d numeri: ", LUNG);
    int numeri[LUNG];

    for(int i = 0; i < LUNG; i++){
        printf("\nNumero %d: ", i+1);
        do{
            scanf("%d", &numeri[i]);

            if(numeri[i] < 0)
                printf("\nInserire solo numeri positivi\n");

        }while(numeri[i] < 0);
    }

    for(int i = 0; i < LUNG; i++){

        int numSeparato[10];
        int lungNum = separaCifre(numeri[i], numSeparato);

        if(isArmstrong(numSeparato, lungNum, numeri[i]))
            printf("\n%d e' un numero di Armstrong", numeri[i]);
        
        else
            numeri[i] = 0;
    }

    return 0;

}