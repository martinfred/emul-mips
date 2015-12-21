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
int SLL(int *rd, int rt, int sa);
int SRL(int *rd, int rt, int sa);
int SLT(int *rd, int rs, int rt);
