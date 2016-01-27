/*
Projet emul-mips
MEMORY.C

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/



#include "memory.h"

int mem[256];

int memoryRead(int i){

	return mem[i];

}

int memoryWrite(int i, int x){


	mem[i] = x;

	return 0;
}

