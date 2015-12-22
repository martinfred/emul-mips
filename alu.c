#include "alu.h"

int ADD(int *rd, int rs, int rt){

	
	if((rs > 0 && rt > INT_MAX - rs) || (rs < 0 && rt < INT_MIN - rs)){

		/* overflow */
		perror("Overflow");
		return -1;

	} else {

		*rd = rs + rt;
		return 0;

	}

}

int ADDI(int * rd, int rs, int i){

	if((rs > 0 && i > INT_MAX - rs) || (rs < 0 && i < INT_MIN - rs)){

		/* overflow */
		perror("Overflow");
		return -1;

	} else {

		*rd = rs + i;
		return 0;

	}

}

int SUB(int *rd, int rs, int rt){

	if ((rs > 0 && rt < rs - INT_MAX) || (rs < 0 && rt > rs - INT_MIN)){
		
		/* overflow */
		perror("Overflow");
		return -1;
	}else{
	
		*rd = rs - rt;
		return 0;
	}
}
int MULT(int *HI,int *LO, int rs, int rt){
	long res;

	res = rs * rt;
	*HI = (res & 0xFFFF0000) >> 16;
	*LO = (res & 0x0000FFFF);
	
	return 0;
}
int DIV(int *HI,int *LO, int rs, int rt){
	long res;

	res = rs / rt;
	*HI = (res & 0xFFFF0000) >> 16;
	*LO = (res & 0x0000FFFF);

	return 0;
}
int AND(int *rd, int rs, int rt){
	*rd = rs & rt;
	return 0;
}
int OR(int *rd, int rs, int rt){
	*rd = rs | rt;
	return 0;
}
int XOR(int *rd, int rs, int rt){
	*rd = rs ^ rt;
	return 0;
}
int ROTR(int *rd, int rt, int sa){
	/*fuuuuuuuuuuu*/
	return 0;
}
int SLL(int *rd, int rt, int sa){
	return 0;
}
int SRL(int *rd, int rt, int sa){
	return 0;
}
int SLT(int *rd, int rs, int rt){
	return 0;
}
int LW(int *rt, int rs, int sa){
	return 0;
}
int SW(int *rs, int sa, int rt){
	return 0;
}
int LUI(int *rt, int sa){
	return 0;
}
int MFHI(int *rd){
	return 0;
}
int MFLO(int *rd){
	return 0;
}
int BEQ(int rs, int rt, int sa){
	return 0;
}
int BNE(int rs, int rt, int sa){
	return 0;
}
int BGTZ(int *rs, int sa){
	return 0;
}
int BLEZ(int *rs, int sa){
	return 0;
}
int J(int sa){
	return 0;
}
int JAL(int sa){
	return 0;
}
int JR(int rs){
	return 0;
}
