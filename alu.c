#include "alu.h"

int MAX = 32767; /* INT_MAX */
int MIN = -32768; /* INT_MIN */

int ADD(int *rd, int rs, int rt){

	if((rs > 0 && rt > MAX - rs) || (rs < 0 && rt < MIN - rs)){

		perror("Overflow");
		return -1;

	} else {

		*rd = rs + rt;

		return 0;

	}

}

int ADDI(int *rd, int rs, int i){

	if((rs > 0 && i > MAX - rs) || (rs < 0 && i < MIN - rs)){

		perror("Overflow");
		return -1;

	} else {

		*rd = rs + i;

		return 0;

	}

}

int SUB(int *rd, int rs, int rt){

	if ((rs > 0 && rt < rs - MAX) || (rs < 0 && rt > rs - MIN)){
		
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

	int hi, lo;

	if(0 != rt){

		hi = 0;
		lo = 0,
	
		hi = rs % rt;
		lo = rs / rt;

		registersWrite(nti("hi"),hi);
		registersWrite(nti("lo"),lo);

	}
	
	return 0;

}
