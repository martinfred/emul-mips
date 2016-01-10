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

	/*
	while(1){

		printf("hi : %d\n",registersRead(nti("hi")));
		
		registersWrite(nti("hi"),18);

		printf("hi : %d\n",registersRead(nti("hi")));

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

			inst = compile(instruction);

			printf("compile : %X\n",inst);

			exe(inst);

			registersDisplay();
		}

	saveRegisters(0);

	}
	
	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
