#include <string.h>

/* registers initialisation */
int registersInit(void);

/* This function write the interger n in the register r */
int registersWrite(int r, int n);

/* This function retrun the value of the register r*/
int registersRead(int r);

/* name to indice */
int nti(char name[]);

