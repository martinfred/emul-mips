/*
Projet emul-mips
MEMORY.H

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/


/* This function return the value at the adresse i in the memory */
int memoryRead(int i);

/* this function write the value x in the adresse i of the memory */
int memoryWrite(int i, int x);

