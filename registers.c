#include "registers.h"

int registers[35];

int registersInit(void){

	int i = 0;

	for(i = 0; i < 35; i++){

		registers[i] = 0;

	}

	return 0;

}


int registersWrite(int r, int n){

	int i = -1;

	if(r > 0 && r <= 35){	

		registers[r] = n;

		i = 0;

	}

	
	return i;	

}

int registersRead(int r){

	return registers[r];
}

int nti(char name[]){

	int i = -1;
	int j;


	/* all char in lowercase*/

	j = 0;

	while('\0' != name[j]){

		if('A' <= name[j] && 'Z' >= name[j]){

			name[j] += 32;

		}

		j++;

	}




	if(strcmp("zero",name) == 0){

		i = 0;

	}

	if(strcmp("at",name) == 0){

		i = 1;

	}

	if(strcmp("v0",name) == 0){

		i = 2;

	}

	if(strcmp("v1",name) == 0){

		i = 3;

	}

	if(strcmp("a0",name) == 0){

		i = 4;

	}

	if(strcmp("a1",name) == 0){

		i = 5;

	}


	if(strcmp("a2",name) == 0){

		i = 6;

	}

	if(strcmp("a3",name) == 0){

		i = 7;

	}

	if(strcmp("t0",name) == 0){

		i = 8;

	}

	if(strcmp("t1",name) == 0){

		i = 9;

	}

	if(strcmp("t2",name) == 0){

		i = 10;

	}

	if(strcmp("t3",name) == 0){

		i = 11;

	}

	if(strcmp("t4",name) == 0){

		i = 12;

	}

	if(strcmp("t5",name) == 0){

		i = 13;

	}

	if(strcmp("t6",name) == 0){

		i = 14;

	}

	if(strcmp("t7",name) == 0){

		i = 15;

	}

	if(strcmp("s0",name) == 0){

		i = 16;

	}

	if(strcmp("s1",name) == 0){

		i = 17;

	}

	if(strcmp("s2",name) == 0){

		i = 18;

	}

	if(strcmp("s3",name) == 0){

		i = 19;

	}

	if(strcmp("s4",name) == 0){

		i = 20;

	}

	if(strcmp("s5",name) == 0){

		i = 21;

	}

	if(strcmp("s6",name) == 0){

		i = 22;

	}

	if(strcmp("s7",name) == 0){

		i = 23;

	}

	if(strcmp("t8",name) == 0){

		i = 24;

	}

	if(strcmp("t9",name) == 0){

		i = 25;

	}

	if(strcmp("k0",name) == 0){

		i = 26;

	}

	if(strcmp("k1",name) == 0){

		i = 27;

	}

	if(strcmp("gp",name) == 0){

		i = 28;

	}

	if(strcmp("sp",name) == 0){

		i = 29;

	}

	if(strcmp("fp",name) == 0){

		i = 30;

	}

	if(strcmp("ra",name) == 0){

		i = 31;

	}

	if(strcmp("pc",name) == 0){

		i = 32;

	}

	if(strcmp("lo",name) == 0){

		i = 33;

	}

	if(strcmp("hi",name) == 0){

		i = 34;

	}


	return i;
}


