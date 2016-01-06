#include "save.h"

int saveMemory(void){




	return 0;
}

int saveRegisters(void){

	FILE *registers;
	



	registers = fopen("registers.sav", "w");

	if(NULL == registers){

		perror("registers save error\n");
		return -1;

	}


	fprintf(registers,"MIPS registers : \n\n");

	fprintf(registers,"[ 0] zero : %d\n",registersRead(0));
	fprintf(registers,"[ 1] at : %d\n",registersRead(1));
	fprintf(registers,"[ 2] v0 : %d\n",registersRead(2));
	fprintf(registers,"[ 3] v1 : %d\n",registersRead(3));
	fprintf(registers,"[ 4] a0 : %d\n",registersRead(4));
	fprintf(registers,"[ 5] a1 : %d\n",registersRead(5));
	fprintf(registers,"[ 6] a2 : %d\n",registersRead(6));
	fprintf(registers,"[ 7] a3 : %d\n",registersRead(7));
	fprintf(registers,"[ 8] t0 : %d\n",registersRead(8));
	fprintf(registers,"[ 9] t1 : %d\n",registersRead(9));
	fprintf(registers,"[10] t2 : %d\n",registersRead(10));
	fprintf(registers,"[11] t3 : %d\n",registersRead(11));
	fprintf(registers,"[12] t4 : %d\n",registersRead(12));
	fprintf(registers,"[13] t5 : %d\n",registersRead(13));
	fprintf(registers,"[14] t6 : %d\n",registersRead(14));
	fprintf(registers,"[15] t7 : %d\n",registersRead(15));
	fprintf(registers,"[16] s0 : %d\n",registersRead(16));
	fprintf(registers,"[17] s1 : %d\n",registersRead(17));
	fprintf(registers,"[18] s2 : %d\n",registersRead(18));
	fprintf(registers,"[19] s3 : %d\n",registersRead(19));
	fprintf(registers,"[20] s4 : %d\n",registersRead(20));
	fprintf(registers,"[21] s5 : %d\n",registersRead(21));
	fprintf(registers,"[22] s6 : %d\n",registersRead(22));
	fprintf(registers,"[23] s7 : %d\n",registersRead(23));
	fprintf(registers,"[24] t8 : %d\n",registersRead(24));
	fprintf(registers,"[25] t9 : %d\n",registersRead(25));
	fprintf(registers,"[26] k0 : %d\n",registersRead(26));
	fprintf(registers,"[27] k1 : %d\n",registersRead(27));
	fprintf(registers,"[28] gp : %d\n",registersRead(28));
	fprintf(registers,"[29] sp : %d\n",registersRead(29));
	fprintf(registers,"[30] fp : %d\n",registersRead(30));
	fprintf(registers,"[31] ra : %d\n\n",registersRead(31));

	fprintf(registers,"lo : %d\n",registersRead(32));
	fprintf(registers,"hi : %d\n",registersRead(33));

	fclose(registers);

	return 0;
}
