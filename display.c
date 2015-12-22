#include "display.h"

int memoryDisplay(void){

	int i;

	for(i = 0; i < 30; i++){

		printf("%d : %d\n",i,memoryRead(i));

	}

	return 0;

}
