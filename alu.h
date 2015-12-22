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
int LW(int *rt, int rs, int sa);
int SW(int *rs, int sa, int rt);
int LUI(int *rt, int sa);
int MFHI(int *rd);
int MFLO(int *rd);
int BEQ(int rs, int rt, int sa);
int BNE(int rs, int rt, int sa);
int BGTZ(int *rs, int sa);
int BLEZ(int *rs, int sa);
int J(int sa);
int JAL(int sa);
int JR(int rs);
