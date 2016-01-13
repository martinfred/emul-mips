/*
ALU.H
Projet emul-mips

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/


#include <math.h>
#include <stdio.h>
#include <limits.h>

#include "registers.h"


int ADD(int *rd, int rs, int rt);
int ADDI(int *rd, int rs, int i);
int SUB(int *rd, int rs, int rt);
int MULT(int rs, int rt);
int DIV(int rs, int rt);



