#include "controlUnit.h"

int run(int adresse){


	if(-1 == registersWrite(nti("fp"),adresse)){

		perror("first instruction error");
		return -1;

	}

	while(memoryRead(registersRead(nti("fp"))) != 0){
		
		/*________Instruction Fetch________*/			

		if(0 != exe(memoryRead(adresse))){
			
			perror("instruction execution error !");
			return -1;

		}

		/* if(adresse > 4096) */		

	}

	return 0;

}



int exe(int instruction){

	int opCode;
	int type = -1;

	int rs, rt, rd, arg, hi, lo;
	int irs, irt, ird, ihi, ilo;
	
	
	/*________Instruction Decode________*/
	/*________Register Fetch________*/

	if(((63 << 26) & instruction) == 0) /* SPECIAL */
	{ 
		opCode = instruction & 63;	/*masque*/
		/*RTYPE*/
		irs = (31 << 21) & instruction;
		irt = (31 << 16) & instruction;
		ird = (31 << 11) & instruction;
		arg = 0xFFFF & instruction;

	}else{
		opCode = instruction & (63 << 26);	/*masque*/

		if ((opCode == 2) | (opCode == 3))
		{
			/*JTYPE*/
			arg = 0x3FFFFFF & instruction;
		}else{
			/*ITYPE*/
			irs = (31 << 21) & instruction;
			irt = (31 << 16) & instruction;
		}	arg = 0xFFFF & instruction;
	}

	printf("opCode : %d\n",opCode); /* DEBUG */

	rs = registersRead(irs);
	rt = registersRead(irt);
	rd = 0;

	/*_______Execute_________*/
	
	switch(opCode){

		case 32 :
			ADD(&rd, rs, rt);
			registersWrite(ird,rd);
			fpInc();
			break;

		case 8 :
			ADDI(&rd, rs, arg);
			registersWrite(ird,rd);
			fpInc();
			break;

/*
		case 36 :
			AND(&rd, rs, rt);
			break;

		case 4 :
			BEQ(rs, rt, arg);
			break;

		case 7 :
			BGTZ(&rs, arg);
			break;

		case 6 :
			BLEZ(&rs, arg);
			break;

		case 5 :
			BNE(rs, rt, arg);
			break;

		case 26 :
			DIV(&hi, &lo, rs, rt);
			break;

		case 2 :
			J(arg);
			break;

		case 3 :
			JAL(arg);
			break;

		case 8 :
			JR(rs);
			break;

		case 15 :
			LUI(&rt, arg);
			break;

		case 35 :
			LW(&rt, rs, arg);
			break;

		case 16 :
			MFHI(&rd);
			break;

		case 18 :
			MFLO(&rd);
			break;

		case 24 :
			MULT(&hi, &lo, rs, rt);
			break;

		case 37 :
			OR(&rd, rs, rt);
			break;

		case 2 :
			ROTR(&rt, rs, arg);
			break;

		case 0 : 
			SLL(&rd, rs, arg);
			break;

		case 42 : 
			SLT(&rd, rs, rt);
			break;

		case 2 : 
			SRL(&rd, rs, arg);
			break;

		case 34 : 
			SUB(&rd, rs, rt);
			break;

		case 43 : 
			SW(&rs, arg, rt);
			break;

		case 12 : 
			SYSCALL();
			break;

		case 38 : 
			 XOR(&rd, rs, rt) 
			break;

		*/

		default :
			printf("ERROR instruction\n");
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


int fpInc(void){

	int fp;

	fp = registersRead(nti("fp"));

	fp++;

	registersWrite(nti("fp"),fp);

	return fp;

}
