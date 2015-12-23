#include <stdio.h>
#include <string.h>

#include "compiler.h"
#include "memory.h"

int main(int argc, char *argv[]){

	char instruction[100];
	char file[100];
	
	int inst;

	int i;

	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");
	printf("       V1 - traduction des instrucions      \n\n");


	if(argc == 2){ /*__________mode file__________*/

		/*___________file comilation__________*/

		printf("File mode ...");

		fileCompile(argv[1],file);
 	

	} else { /*__________mode live__________*/

		printf("Welcome in live mode ...\n");
	
		while(1){


			printf("Instruction : ");
		
			fgets (instruction, 100, stdin);

			/* majuscule */

			i = 0;

			while('\0' != instruction[i]){		

				if(97 <= instruction[i] && 122 >= instruction[i]){
		
					instruction[i] -= 32;

				}
				
				i++;
			}

			printf("INSTRUCTION : %s",instruction);
			
	  		if(strcmp(instruction,"EXIT\n") == 0) break; /*fgets add  \n at the end */

			inst = compile(instruction);

			printf("Compile : %X\n",inst);

			
		}


	}


	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
