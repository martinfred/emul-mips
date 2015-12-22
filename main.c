#include <stdio.h>
#include <string.h>

#include "compiler.h"
#include "memory.h"

int main(int argc, char *argv[]){

	char instruction[100];
	char file[100];
	
	int inst;
	int rd, rs, rt;

	int i;

	printf("\n\n\n         <[°_°]> EMUL MIPS <[°_°]>         \n\n\n");
	
		while(1)
		{

			printf("Instruction : ");
		
			fgets (instruction, 100, stdin);
			
	  		if(strcmp(instruction,"EXIT\n") == 0) break; /*fgets add  \n at the end */
			inst = compile(instruction);
			printf("compile : %X\n",inst);

			run(inst);

			
		}

	printf("\n\n         <[°_°]>  THE END  <[°_°]>         \n\n");

	return 0;

}
