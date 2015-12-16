#include <stdio.h>
#include <string.h>

#include "compiler.h"
#include "display.h"
#include "registers.h"
#include "controlUnit.h"
#include "alu.h"
#include "memory.h"

int main(int argc, char *argv[]){

	char instruction[100];
	char file[100];
	
	int inst;
	int rd, rs, rt;

	int i;

	rs = 2000000000;
	rt = 200000000;


	
	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");

	if(argc == 2){ /*__________mode file__________*/

		/*___________file comilation__________*/

		memoryCompile(argv[1]);
		fileCompile(argv[1],file);
 	
		/* printf("file : %s\n",file); ????? */

		memoryDisplay();




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

			run(inst);
		}


	}


	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
