//
//If possible add an item into an array of finite space (LUNG), shifting the others ahead
//

#include <stdio.h>
#define LUNG 10

int leggi(int arr[], int lung){
    
    do{

        scanf("%d", &arr[lung]);
        if(arr[lung] != -1)
            lung++;

    }while(arr[lung] != -1 && lung < LUNG);

    printf("\nlung: %d", lung);

    return lung;
}

int shift(int arr[], int lung, int numero, int pos){

    for(int i = lung; i > pos-1; i--)
        arr[i] = arr[i-1];
    
    arr[pos] = numero;

    return lung+1; 
}

int main(){

    printf("Numeri positivi: (-1 per fermarsi, massimo %dnum)\n", LUNG);
    int arr[LUNG] = {0};
    int lungLogica = leggi(arr, 0);

    if(lungLogica == LUNG){
        printf("\nArray pieno, operazione di shift impossibile");
        return 0;
    }

    printf("\nNumero da inserire: ");
    int numero;
    scanf("%d", &numero);
    
    printf("\nPosizione dove inserire: (partendo da 0)\n");
    int pos;

    do{
        scanf("%d", &pos);
        if(pos < 0 || pos > lungLogica)
            printf("\nPosizione non valida, reinserirla: ");
    }while(pos < 0 || pos > lungLogica);

    lungLogica = shift(arr, lungLogica, numero, pos);

    printf("\nArray aggiornato: ");
    for(int i = 0; i < lungLogica; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}