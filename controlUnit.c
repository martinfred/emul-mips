/*
Projet emul-mips
CONTROLUNIT.C

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/



#include "controlUnit.h"

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

		mode = 1;

		while(memoryRead(registersRead(nti("pc"))) != 0){
		

		/*________Instruction execution________*/			
	
			if(0 != exe(memoryRead(registersRead(nti("pc"))),mode)){
			
				perror("instruction execution error");
				return -1;
			}

		}

		return 0;

	} else {

		/* step by step mode */

		printf("Welocome in Step by Step mode !\n");
		printf("press enter to begin\n");
		
		getchar();
		
		while(memoryRead(registersRead(nti("pc"))) != 0){
		

		/*________Instruction execution________*/			


			printf("\033[H\033[2J");

	
			if(0 != exe(memoryRead(registersRead(nti("pc"))),mode)){
			
				perror("instruction execution error");
				return -1;
			}

			registersDisplay();
	
	

			printf("press enter to continue\n");
		
			getchar();



		}

		return 0;

	}

}



int exe(int instruction, int mode){

	int opCode;
	int spec = -1;
	
	int rs, rt, rd, arg;
	int irs, irt, ird;
	
	irs = 0;
	irt = 0;
	ird = 0;

	rs = 0;
	rt = 0;
	rd = 0;
	arg = 0;

	
	/*________Register Fetch________*/

	if(((0x3F << 26) & instruction) == 0) /* SPECIAL */
	{ 
		spec = 1;
		opCode = instruction & 63;	/*masque*/
		/*RTYPE*/
		irs = ((0x1F << 21) & instruction) >> 21;
		irt = ((0x1F << 16) & instruction) >> 16;
		ird = ((0x1F << 11) & instruction) >> 11;


		arg = 0xFFFF & instruction;
				

	}else{ /* not SPECIAL */

		spec = 0;
		opCode = (instruction & (0x3F << 26)) >> 26;	/*masque*/

		if ((opCode == 2) | (opCode == 3)){
		
			arg = 0x3FFFFFF & instruction;

		}else{

			irs = ((0x1F << 21) & instruction) >> 21;
			irt = ((0x1F << 16) & instruction) >> 16;
		
			if(0 == (instruction & (0x1 << 15))){ 

				arg = 0xFFFF & instruction;
				
			} else { /* argument négatif */
						
				arg = -(1 + ~((0xFFFF << 16) | (0xFFFF & instruction)));

			}
		
		}

	}

	rs = registersRead(irs);
	rt = registersRead(irt);
	rd = registersRead(ird);

	/*_______Execute_________*/

	printf("irs : %d, irt : %d, ird : %d\n",irs,irt,ird);
	printf("rs : %d, rt : %d, rd : %d\n",rs,rt,rd);
	printf("arg : %d\n",arg);



	if(0  == spec){

		switch(opCode){

			case 8 : /* ADDI */

				if(1 == mode) printf("ADDI $%d, $%d, %d\n",irs,irt,arg);

				if(0 != ADDI(&rt, rs, arg)){
			
					perror("ADDI error");
					return -1;

				}

				registersWrite(irt,rt);
				pcInc();
				break;

			case 4 : /* BEQ */

				if(1 == mode) printf("BEQ $%d, $%d, %d\n",irs,irt,arg);

				if(rs == rt){
		
					registersWrite(nti("pc"),registersRead(nti("pc")) + arg);
		
				}else{
		
					pcInc();
		
				}

				break;

			case 7 : /* BGTZ */

				if(1 == mode) printf("BGTZ $%d, %d\n",irs,arg);

				if(rs > 0){
		
					registersWrite(nti("pc"),registersRead(nti("pc")) +  arg);
		
				}else{
		
					pcInc();
		
				}
	
				break;

			case 6 : /* BLEZ */

				if(1 == mode) printf("BLEZ $%d, %d\n",irs,arg);

				if(rs <= 0){
		
					registersWrite(nti("pc"),registersRead(nti("pc")) +  arg);
		
				}else{
		
					pcInc();
		
				}
				break;

			case 5 : /* BNE */
			
				if(1 == mode) printf("BNE $%d, $%d, %d\n",irs,irt,arg);
		
				if(rs != rt){
			
					registersWrite(nti("pc"),registersRead(nti("pc")) + arg);
			
				}else{
				
					pcInc();
		
				}
				break;

			case 15 : /* LUI : Load Upper Immediate */
			
				if(1 == mode) printf("LUI $%d, %d\n",irt,arg);

				registersWrite(irt,(arg << 16));
				pcInc();
				break;

			case 35 : /* LW : LOAD WORD */
	
				/* base = irs */

				if(1 == mode) printf("LW $%d, %d(%d)\n",irt,arg,irs);
			
				registersWrite(irt,memoryRead(irs + arg));
				pcInc();
				break;

			case 43 : /* SW : Store Word */
		
				if(1 == mode) printf("SW $%d, %d(%d)\n",irt,arg,irs);
	
				memoryWrite(rs + arg,rt);
				pcInc();
				break;

			case 2 : /* J*/
				registersWrite(nti("pc"), arg);
				break;
		
			default :

				perror("instruction error");		
				return -1;
		}

	}else{ /* spec == 1 */

		switch(opCode){

			case 32 :  /* ADD */

				if(1 == mode) printf("ADD $%d,$%d,$%d\n",ird,irs,irt);
	
				if(0 !=	ADD(&rd, rs, rt)){

					perror("ADD error");
					return -1;	

				}

				registersWrite(ird,rd);
				pcInc();
				break;

			case 36 : /* AND */

				if(1 == mode) printf("AND $%d, $%d, $%d\n",irs,irt,ird);
	
				rd = rs & rt;
				registersWrite(ird,rd),
				pcInc();
				break;

			case 26 : /* DIV */

				if(1 == mode) printf("DIV $%d, $%d\n",irs,irt);

				if(0 != DIV(rs, rt)){

					perror("DIV error");
					return -1;
		
				}

				pcInc();
				break;

			case 16 : /* MFHI : MOVE FROM HI */

				if(1 == mode) printf("MFHI $%d\n",ird);

				registersWrite(ird,registersRead(nti("hi")));
				pcInc();
				break;

			case 18 : /* MFLO : MOVE FROM LO */

				if(1 == mode) printf("MFLO $%d\n",ird);

				registersWrite(ird,registersRead(nti("lo")));
				pcInc();
				break;

			case 24 : /* MULT */

				if(1 == mode) printf("MULT $%d, $%d\n",irs,irt);

				if(0 != MULT(rs, rt)){

					perror("MULT error");
					return -1;

				}

				pcInc();
				break;

			/* NOP ? */


			case 37 : /* OR */

				if(1 == mode) printf("OR $%d, $%d, $%d\n",irs,irt,ird);

				rd = rs | rt;
				registersWrite(ird,rd);
				pcInc();	
				break;

			case 0 : /* SLL : Shift Word Left Logical */

				if(1 == mode) printf("SLL $%d, $%d, %d\n",ird,irt,arg);

				rd = rt << arg;
				break;

			case 42 : /* SLT : Set on Less Than */  

				if(1 == mode) printf("SLT $%d, $%d, $%d\n",irs,irt,ird);

				if(rs < rt){

					rd = 1;

				}else{

					rd = 0;

				}
		
				registersWrite(ird,rd);
				pcInc();
				break;

			case 2 : /* SRL & ROTR */

			

				if((instruction & (0x1 << 21)) == 0){ /* SRL */
			
					if(1 == mode) printf("SRL $%d, $%d, $%d\n",irs,irt,ird);
	
					rd = rt >> arg;
	
				}else{ /* ROTR */
					
					if(1 == mode) printf("ROTR $%d, $%d, $%d\n",irs,irt,ird);


				}

				pcInc();
				break;

			case 34 : /* SUB */

				if(1 == mode) printf("SUB $%d, $%d, $%d\n",irs,irt,ird);

				if(0 != SUB(&rd, rs, rt)){

					perror("SUB error");
					return -1;
			
				}

				registersWrite(ird,rd);
				pcInc();
				break;

			case 38 : /* XOR */

				if(1 == mode) printf("XOR $%d, $%d, $%d\n",irs,irt,ird);

				rd = rs ^ rt;
				registersWrite(ird,rd); 
				break;

			default :

				perror("instruction error");		
				return -1;
	
		}
	}

	return 0;
}

/*		case 2 :
			J(arg);
			break;
		case 3 :
			JAL(arg);
			break;
		case 8 :
			JR(rs);
			break;
		case 2 :
			ROTR(&rt, rs, arg);
			break;
		case 12 : 
			SYSCALL();
			break;
*/


		


int pcInc(void){

	int pc;

	pc = registersRead(nti("pc"));

	pc += 1;

	registersWrite(nti("pc"),pc);

	return pc;

}

/*


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

*/
