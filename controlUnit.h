#include <stdio.h>

#include "alu.h"
#include "registers.h"
#include "memory.h"

/* This function manage the instruction of a program*/
int run(int adresse);

/* This function execute one instruction */
int exe(int instruction);

/* frame pointer increment */
int fpInc(void);


