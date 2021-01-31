//
//If possible remove an item into an array of finite space (LUNG), shifting the others behind
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

int drop(int arr[], int lung, int pos){

    for(int i = pos; i < lung; i++)
        arr[i] = arr[i+1];

    return lung-1;

}

int main(){

    printf("Numeri positivi: (-1 per fermarsi, massimo %dnum)\n", LUNG);
    int arr[LUNG] = {0};
    int lungLogica = leggi(arr, 0);

    if(lungLogica == 0){
        printf("\nArray vuoto, operazione di drop impossibile");
        return 0;
    }
    
    printf("\nPosizione da eliminare: (partendo da 0)\n");
    int pos;

    do{
        scanf("%d", &pos);
        if(pos < 0 || pos > lungLogica-1)
            printf("\nPosizione non valida, reinserirla: ");
    }while(pos < 0 || pos > lungLogica-1);

    lungLogica = drop(arr, lungLogica, pos);

    printf("\nArray aggiornato: ");
    for(int i = 0; i < lungLogica; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}