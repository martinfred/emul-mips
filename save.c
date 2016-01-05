#include "save.h"

int saveMemory(void){




	return 0;
}

int saveRegisters(void){

	FILE *registers;
	
	int i;


	registers = fopen("registers.mips", "w");

	if(NULL == registers){

		perror("registers save error\n");
		return -1;

	}

	for(i = 0; i < 34; i++){

		fprintf(registers,"r[%d] = %d\n",i,registersRead(i));

	}

	fclose(registers);

	return 0;
}
