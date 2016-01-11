#include <stdio.h>
#include <math.h>

#include "alu.h"
#include "registers.h"
#include "memory.h"

/* This function manage the instruction of a program*/
int run(int adresse, int mode);

/* This function execute one instruction */
int exe(int instruction, int mode);

/* frame pointer increment */
int pcInc(void);



