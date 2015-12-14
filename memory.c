#include "memory.h"

int mem[4096];

int memoryRead(int i){

	return mem[i];

}

int memoryWrite(int i, int x){


	mem[i] = x;

	return 0;
}

