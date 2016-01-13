/*
Projet emul-mips
CONTROLUNIT.H

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/



#include <stdio.h>
#include <math.h>

#include "alu.h"
#include "registers.h"
#include "memory.h"
#include "display.h"

/* This function manage the instruction of a program*/
int run(int adresse, int mode);

/* This function execute one instruction */
int exe(int instruction, int mode);

/* frame pointer increment */
int pcInc(void);



