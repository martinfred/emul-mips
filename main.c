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
	char file[100];

	int inst;	
	int i;

	/*

	while(1){

		printf("fp : %d\n",registersRead(nti("fp")));
		
		fpInc();

		printf("fp : %d\n",registersRead(nti("fp")));

		return 0;

	}


	*/



	
	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");

	if(argc == 2){ /*__________mode file__________*/

		/*___________file comilation__________*/

		memoryCompile(argv[1]);
		fileCompile(argv[1],file);
 	
		/* printf("file : %s\n",file); ????? */

		run(0);

		saveRegisters();

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

		saveRegisters();

	}


	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
