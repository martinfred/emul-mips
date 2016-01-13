/*
Projet emul-mips
REGISTERS.H

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/



#include <string.h>

/* registers initialisation */
int registersInit(void);

/* This function write the interger n in the register r */
int registersWrite(int r, int n);

/* This function retrun the value of the register r*/
int registersRead(int r);

/* name to indice */
int nti(char name[]);

