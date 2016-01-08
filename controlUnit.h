#include <stdio.h>
#include <math.h>

#include "alu.h"
#include "registers.h"
#include "memory.h"

/* This function manage the instruction of a program*/
int run(int adresse);

/* This function execute one instruction */
int exe(int instruction);

/* frame pointer increment */
int pcInc(void);

int AND(int *rd, int rs, int rt);

int OR(int *rd, int rs, int rt);

int XOR(int *rd, int rs, int rt);

int ROTR(int *rd, int rt, int sa);

int SLL(int *rd, int rt, int sa);

int SRL(int *rd, int rt, int sa);
