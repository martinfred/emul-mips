#include "registers.h"

int registers[32];

void registersWrite(int r, int n){

	registers[r] = n;

}

int registersRead(int r){

	return registers[r];
}

