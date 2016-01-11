#include "display.h"

int memoryDisplay(void){

	int i;

	for(i = 0; i < 30; i++){

		printf("%d : %d\n",i,memoryRead(i));

	}

	return 0;

}

int registersDisplay(void){

	printf("MIPS registers : \n\n");

	printf("[ 0] zero : %d\t",registersRead(0));
	printf("[ 1] at : %d\n",registersRead(1));
	printf("[ 2] v0 : %d\t",registersRead(2));
	printf("[ 3] v1 : %d\n",registersRead(3));
	printf("[ 4] a0 : %d\t",registersRead(4));
	printf("[ 5] a1 : %d\n",registersRead(5));
	printf("[ 6] a2 : %d\t",registersRead(6));
	printf("[ 7] a3 : %d\n",registersRead(7));
	printf("[ 8] t0 : %d\t",registersRead(8));
	printf("[ 9] t1 : %d\n",registersRead(9));
	printf("[10] t2 : %d\t",registersRead(10));
	printf("[11] t3 : %d\n",registersRead(11));
	printf("[12] t4 : %d\t",registersRead(12));
	printf("[13] t5 : %d\n",registersRead(13));
	printf("[14] t6 : %d\t",registersRead(14));
	printf("[15] t7 : %d\n",registersRead(15));
	printf("[16] s0 : %d\t",registersRead(16));
	printf("[17] s1 : %d\n",registersRead(17));
	printf("[18] s2 : %d\t",registersRead(18));
	printf("[19] s3 : %d\n",registersRead(19));
	printf("[20] s4 : %d\t",registersRead(20));
	printf("[21] s5 : %d\n",registersRead(21));
	printf("[22] s6 : %d\t",registersRead(22));
	printf("[23] s7 : %d\n",registersRead(23));
	printf("[24] t8 : %d\t",registersRead(24));
	printf("[25] t9 : %d\n",registersRead(25));
	printf("[26] k0 : %d\t",registersRead(26));
	printf("[27] k1 : %d\n",registersRead(27));
	printf("[28] gp : %d\t",registersRead(28));
	printf("[29] sp : %d\n",registersRead(29));
	printf("[30] fp : %d\t",registersRead(30));
	printf("[31] ra : %d\n\n",registersRead(31));

	printf("pc : %d\n\n",registersRead(32));

	printf("lo : %d\t",registersRead(33));
	printf("hi : %d\n\n",registersRead(34));






	return 0;
}
