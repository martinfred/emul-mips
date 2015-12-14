#include "alu.h"

int ADD(int * rd, int rs, int rt){

	
	if((rs > 0 && rt > INT_MAX - rs) || (rs < 0 && rt < INT_MIN - rs)){

		/* overflow */
		perror("Overflow");
		return -1;

	} else {

		*rd = rs + rt;
		return 0;

	}

}
