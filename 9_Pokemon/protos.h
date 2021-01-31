#ifndef PROTOS_H_
#define PROTOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define MAXSTRLEN 20

typedef struct Mossa{

    char nome[MAXSTRLEN];
    float danno;

} Mossa;

typedef struct Pokemon{

	char nome[MAXSTRLEN];
	int vita;  
	Mossa mossa1;
	Mossa mossa2;

} Pokemon;

int sceltaPvp();
char* dropN(char* str);
Mossa inputMossa();
Pokemon inputPokemon();
Mossa scegliMossaPlayer(Pokemon *p);
Mossa scegliMossaPc(Pokemon *p);
int battleEnd(Pokemon *p1, Pokemon *p2);
int combattimentoPvE(Pokemon p1, Pokemon p2);

#endif