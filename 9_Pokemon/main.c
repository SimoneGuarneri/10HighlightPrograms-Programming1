//Here is the assignment
//https://www.notion.so/simoneguarneri/Tracce-per-Esame-f1a3da71242c4db5a4accb3ca0085c49#a8468b45c9974a1d9b92493f92388810

#include "protos.h"

int main(){
    
    if(!sceltaPvp()){

        printf("\nPlayer\n");
        Pokemon p1 = inputPokemon();
        
        printf("\nComputer\n");
        Pokemon p2 = inputPokemon();

        int vincitore = combattimentoPvE(p1, p2);

        if(vincitore == 1)
            printf("\nPlayer Vince");
        else
            printf("\nComputer Vince");

    }
    else{
        printf("\nPlayer1\n");
        Pokemon p1 = inputPokemon();
        
        printf("\nPlayer2\n");
        Pokemon p2 = inputPokemon();

        int vincitore = combattimentoPvP(p1, p2);

        if(vincitore == 1)
            printf("\n%s Vince", p1.nome);
        else
            printf("\n%s Vince", p2.nome);
    }
    
    return 0;
}