#include "controlUnit.h"

int run(int adresse){


	while(memoryRead(adresse) != 0){
		
		/*________Instruction Fetch________*/			

		if(0 != exe(memoryRead(adresse))){
			
			perror("inxtruction execution error !");
			return -1;

		}

		/* PC !!! */

		adresse++;

		/* if(adresse > 4096) */		

	}

	return 0;

}



int exe(int instruction){

	int opCode;

	int rs,rt,rd,arg;
	int irs, irt, ird;
	
	/*________Instruction Decode________*/


	if(0 == ((63 << 26) & instruction)){ /* SPECIAL */

		opCode = instruction & 63;

	} else {

		opCode = instruction & (63 << 26);

	}

	printf("opCode : %d\n",opCode); /* DEBUG */


	/*________Register Fetch________*/

	/* lol lol plop plop ... */	
	irs = (31 << 21) & instruction;
	irt = (31 << 16) & instruction;
	ird = (31 << 11) & instruction;
	arg = 65535 & instruction;

	rs = registersRead(rs);
	rt = registersRead(rt);


	/*_______Execute_________*/
	
	switch(opCode){


		case 8 :
			/* ADDI(&rd,rs,arg); */
			break;

		case 26 :
			DIV(&rd,rs,rt);
			break;
		
		case 32 :
			ADD(&rd,rs,rt);
			break;
	
	}

	/*

int ADD(int * rd, int rs, int rt);
int ADDI(int * rd, int rs, int i);
int SUB(int *rd, int rs, int rt);
int MULT(int *HI, int *LO, int rs, int rt);
int DIV(int *HI, int *LO, int rs, int rt);

	*/

	/*_________Memory Acess________*/
	

	registersWrite(ird,rd);

	return 0;
}

