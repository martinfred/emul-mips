/*
Projet emul-mips
MAIN.C

Martin FRAY (martin.fray@etu.esisar.grenoble-inp.fr)
Quentin FRITAYRE (quentin.fritayre@etu.grenoble-inp.fr)

Grenoble INP - esisar
P2018

Valence
13 janvier 2016
*/



#include <stdio.h>
#include <string.h>

#include "compiler.h"
#include "display.h"
#include "registers.h"
#include "controlUnit.h"
#include "alu.h"
#include "memory.h"
#include "save.h"

int main(int argc, char *argv[]){

	char instruction[100];

	int inst;	
	int i;
	int mode = 0; /* 0 : one shot, 1 : step by step */
	int nbsave = 0;

	printf("\033[H\033[2J");




/*  <[°_°]> debug <[°_°]>  */

/*
	while(1){

		printf("SW - LW\n");
		
		memoryWrite(22,42);

		printf("%d\n",memoryRead(22));


		return 0;

	}
*/	




	
	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");

	if(argc != 1){ /*__________mode file__________*/

		if(argc > 2){

			if(0 == strcmp(argv[2],"-pas")){
				
				printf("Step by step mode\n");
				mode = 1;

			} else {

				printf("Sorry, \"%s\" is not an available option.\n",argv[2]);
		
			}

		}
			

				
		memoryCompile(argv[1]);
		
		run(0,mode);
	
		saveRegisters(0);
		saveMemory(0);

		
	} else { /*__________mode live__________*/

		printf("Welcome in live mode !\n");
		printf("Here, you can use only few instructions :\n");
		printf("ADD, ADDI, MULT, SUB, DIV, ...\n");		
		
	
		while(1){

			printf("\"EXIT\" to close, \"SAVE\" to save registers\n"); 
			printf("Instruction : ");
		
			fgets (instruction, 100, stdin);
			
			i = 0;

			while('\0' != instruction[i]){

				if('a' <= instruction[i] && 'z' >= instruction[i]){

					instruction[i] -= 32;

				}

				i++;

			}

			
	  		if(strcmp(instruction,"EXIT\n") == 0) break; /*fgets add  \n at the end */

			if(strcmp(instruction,"SAVE\n") == 0){

				saveMemory(nbsave);
			
				nbsave++;
				
				printf("registers save\n");			

			} else {

			/* clean terminal */

				inst = compile(instruction);
	
				if(inst == -1){
				
					printf("erreur dans la compilation\n");

				} else {


					if(0 != exe(inst,0)){

						printf("erreur dans l'execution de l'instruction\n");

					} else {

						printf("\033[H\033[2J");
		
						printf("Instruction : %s",instruction);
						printf("Compile : %X\n",inst);

						registersDisplay();

					}

				}
		}
	}


}
	
	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
