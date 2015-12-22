#include <stdio.h>
#include <string.h> 

#include "memory.h"

/* This function translate a assembleur instruction in binary instruction */
int compile(char instruction[]);

/* This function translate all the instructions from à file .mips to a file .comp */
int fileCompile(char file[], char * fileName);

/* This funcion translate all the instructions from a file .mips to the memory */
int memoryCompile(char file[]);

/* TO DO :
in memory compile : if the input file is a .comp, just copy the instructions from the file to the memory */
