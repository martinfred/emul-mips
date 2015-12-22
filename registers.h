
/* This function write the interger n in the register r */
void registersWrite(int r, int n);

/* This function retrun the value of the register r*/
int registersRead(int r);

/* name to indice */
int nti(char name[]);

/*TO DO :
int -> char

in a program, it will be easier to call  register "cp" for program counter than register 23

or maybe we can add a function which translate a char in a int (the name of a register to the indice of the register

int nti(char name[]);

 */
