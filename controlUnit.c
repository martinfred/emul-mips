#include "controlUnit.h"
#include <math.h>

int run(int adresse, int mode){

	if(-1 == registersInit()){
	
		perror("registers init error\n");
		return -1;

	}

	if(-1 == registersWrite(nti("pc"),adresse)){

		perror("first instruction error");
		return -1;

	}

	if(0 == mode){

		while(memoryRead(registersRead(nti("pc"))) != 0){
		

		/*________Instruction execution________*/			
	
			if(0 != exe(memoryRead(registersRead(nti("pc"))))){
			
				perror("instruction execution error");
				return -1;
			}

		/* if(adresse > 4096) */		

		}

		return 0;

	} else {

		/* step by step mode */

		

		return 0;
	}

}



int exe(int instruction){

	int opCode;
	
	int rs, rt, rd, arg;
	int irs, irt, ird;
	int hi, lo;
	
	irs = 0;
	irt = 0;
	ird = 0;

	/*________Instruction Decode________*/
	/*________Register Fetch________*/

	if(((63 << 26) & instruction) == 0) /* SPECIAL */
	{ 
		opCode = instruction & 63;	/*masque*/
		/*RTYPE*/
		irs = ((31 << 21) & instruction) >> 21;
		irt = ((31 << 16) & instruction) >> 16;
		ird = ((31 << 11) & instruction) >> 11;
		arg = 0xFFFF & instruction;


	}else{
		opCode = (instruction & (63 << 26)) >> 26;	/*masque*/

		if ((opCode == 2) | (opCode == 3))
		{
			/*JTYPE*/
			arg = 0x3FFFFFF & instruction;
		}else{
			/*ITYPE*/
			irs = ((31 << 21) & instruction) >> 21;
			irt = ((31 << 16) & instruction) >> 16;
		}	arg = 0xFFFF & instruction;
	}

	rs = registersRead(irs);
	rt = registersRead(irt);
	rd = registersRead(ird);

	/*_______Execute_________*/
	
	switch(opCode){

		case 32 :
			ADD(&rd, rs, rt);
			registersWrite(ird,rd);
			pcInc();
			break;

		case 8 :
			ADDI(&rt, rs, arg);
			registersWrite(irt,rt);
			pcInc();
			break;


		case 36 :
			AND(&rd, rs, rt);
			registersWrite(ird,rd),
			pcInc();
			break;

/*		case 4 :
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

*/		case 26 :
			DIV(&hi, &lo, rs, rt);
			registersWrite(nti("hi"),hi);
			registersWrite(nti("lo"),lo);
			pcInc();
			break;

/*		case 2 :
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

*/		case 24 :
			MULT(&hi, &lo, rs, rt);
			registersWrite(nti("hi"),hi);
			registersWrite(nti("lo"),lo);
			pcInc();
			break;
		
/*		case 37 :
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

*/		case 34 : 
			SUB(&rd, rs, rt);
			registersWrite(ird,rd);
			pcInc();
			break;

/*		case 43 : 
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
			perror("instruction error");
			return -1;
	}

	return 0;

}


int pcInc(void){

	int pc;

	pc = registersRead(nti("pc"));

	pc++;

	registersWrite(nti("pc"),pc);

	return pc;

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

int SLL(int *rd, int rt, int sa){

	*rd = rt << sa;
	return 0;

}

int SRL(int *rd, int rt, int sa){

	*rd = rt >> sa;
	return 0;

}

int ROTR(int *rd, int rt, int sa){
	
	int k, l;
	int masque = 1;
	int temp;
	int taille;
	
	taille = sizeof(rt);

	for(k = 1; k < sa; k++){
		for(l = 0; l < sa; l++){
			masque *= 2;
		}
	}
	
	temp = rt & masque;
	
	rt = rt >> sa;
	temp = temp << (taille - sa);
	*rd = rt | temp;

	return 0;

}
