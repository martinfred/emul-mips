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


/*

	while(1){

		registersWrite(1,42);

		printf("1 = %d\n",registersRead(1));

		return 0;

	}


*/



	
	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");

	if(argc == 2){ /*__________mode file__________*/

		/*___________file comilation__________*/

		memoryCompile(argv[1]);
		fileCompile(argv[1],file);
 	
		/* printf("file : %s\n",file); ????? */

		memoryDisplay();

		run(0);

		saveRegisters();

	} else { /*__________mode live__________*/

		printf("Welcome in live mode !\n");
		printf("Here, you can use only few instructions :\n");
		printf("ADD, ADDI, MULT, SUB, DIV, ...\n");		

	
		while(1){

			
			printf("Instruction : ");
		
			fgets (instruction, 100, stdin);
			
	  		if(strcmp(instruction,"EXIT\n") == 0) break; /*fgets add  \n at the end */
			inst = compile(instruction);

			printf("compile : %X\n",inst);

			exe(inst);
		}


	}


	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
