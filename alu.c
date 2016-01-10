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

int ADDI(int *rd, int rs, int i){

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

int MULT(int rs, int rt){

	long res;
	int hi, lo;
	
	hi = 0;
	lo = 0;


	res = rs * rt;

	hi = (res & 0xFFFF0000) >> 16;
	lo = (res & 0x0000FFFF);
	
	registersWrite(nti("hi"),hi);
	registersWrite(nti("lo"),lo);


	return 0;

}

int DIV(int rs, int rt){

	long res;
	int hi, lo;

	hi = 0;
	lo = 0,
	
	res = rs / rt;
	hi = (res & 0xFFFF0000) >> 16;
	lo = (res & 0x0000FFFF);

	registersWrite(nti("hi"),hi);
	registersWrite(nti("lo"),lo);

	return 0;
}
