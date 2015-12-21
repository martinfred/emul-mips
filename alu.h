#include <math.h>
#include <stdio.h>
#include <limits.h>

int ADD(int * rd, int rs, int rt);
int ADDI(int * rd, int rs, int i);
int SUB(int *rd, int rs, int rt);
int MULT(int *HI, int *LO, int rs, int rt);
int DIV(int *HI, int *LO, int rs, int rt);
int AND(int *rd, int rs, int rt);
int OR(int *rd, int rs, int rt);
int XOR(int *rd, int rs, int rt);
int ROTR(int *rd, int rt, int sa);
int SLL(int *rd, int rt, int sa);
int SRL(int *rd, int rt, int sa);
int SLT(int *rd, int rs, int rt);
