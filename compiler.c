#include "compiler.h"


int compile(char instruction[]){

	char inst[30];
	char operation[5];

	int opCode = -1;
	int r[3];
	int arg = 0;

	int i, j, n;

	int res = -1;

	r[0] = 0;
	r[1] = 0;
	r[2] = 0;
	arg = 0;	

	/*____________________remove space and comments____________________*/

	i = 0;
	j = 0;

	while((instruction[i] != '#') && (instruction[i] != '\0') && (instruction[i] != '\n')) {

		if(instruction[i] != ' '){

			inst[j] = instruction[i];
			j++;
				
		} 

		i++;	

	}
	
	inst[j] = '\0';

	/*____________________operation____________________*/
	
	i = 0;

	strcpy(operation,"");

	while(('A' <= inst[i])  && ('Z' >= inst[i])){

		sprintf(operation,"%s%c",operation,inst[i]);

		i++;

	}


	/*___________________arguments__________________*/

	j = 0;

	for(i = strlen(operation); i < strlen(inst); i++){
	
		if('$' == inst[i]){

			if((inst[i+1] >= '0') && (inst[i+1] <= '9')){
				if((inst[i+2] >= '0') && (inst[i+2] <= '9')){

					r[j] = (inst[i+1] - '0')*10 + inst[i+2] - '0';
					i += 2;

				}else{

					r[j] = inst[i+1] - '0';
					i ++;

				}

			}else{
				if(inst[i+1] == 'F'){

					if(inst[i+2] == 'P'){
		
						r[j] = nti("fp");
						i += 2;

					}else{

						perror("The register f* not exist");
						return -1;

					}

				}

				if(inst[i+1] == 'Z'){

					if((inst[i+2] == 'E') && (inst[i+3] == 'R') && (inst[i+4] == 'O')){

						r[j] = nti("zero");
						i += 4;

					}else{

						perror("The register z*** not exist");
						return -1;

					}

				}

				if(inst[i+1] == 'R'){

					if(inst[i+2] == 'A'){

						r[j] = nti("ra");
						i += 2;

					}else{

						perror("The register r* not exist");
						return -1;
				
					}
				}

				if(inst[i+1] == 'G'){
				
					if(inst[i+2] == 'P'){

						r[j] = nti("gp");
						i += 2;
				
					}else{

						perror("The register g* not exist");
						return -1;

					}
				}

				if(inst[i+1] == 'S'){

					if(inst[i+2] == 'P'){

						r[j] = nti("sp");
						i += 2;

					}else{
						if((inst[i+2] >= '0') && (inst[i+2] <= '7')){

											
							sprintf(reg,"s%c",inst[i+2]);
							r[j] = nti(reg);
							
							i += 2;

						}else{

							perror("The register s* not exist");
							return -1;

						}	
					}
				}

				if(inst[i+1] == 'T'){

					if((inst[i+2] >= '0') && (inst[i+2] <= '9')){

						sprintf(reg,"t%c",inst[i+2]);
						r[j] = nti(reg);
						
						i += 2;				

					}else{
	
						perror("The register t* not exist");
						return -1;

					}
				}

				if(inst[i+1] == 'V'){

					if((inst[i+2] == '0') || (inst[i+2] == '1')){	

						sprintf(reg,"v%c",inst[i+2]);
						r[j] = nti(reg);
						
						i += 2;

					}else{

						perror("The register v* not exist");
						return -1;

					}						
				}

				if(inst[i+1] == 'A'){

					if(inst[i+2] == 'T'){

						r[j] = nti("at");
						i += 2;	

					}else{
						if((inst[i+2] >= '0') && (inst[i+2] <= '3')){

							sprintf(reg,"a%c",inst[i+2]);
							r[j] = nti(reg);
						
							i += 2;	

						}else{

							perror("The register a* not exist");
							return -1;

						}
					}
				}

				if(inst[i+1] == 'K'){
				
					if((inst[i+2] == '0') || (inst[i+2] == '1')){
						
						sprintf(reg,"k%c",inst[i+2]);
						r[j] = nti(reg);
							
						i += 2;				

					}else{

						perror("The register k* not exist");
						return -1;

					}
				}			
			}

			j++;	

		}else{
	
			if('0' <= inst[i] && '9' >= inst[i]){
			
				j = i;
				n = 1;

				arg = inst[j] - '0';
			
				while( '0' <= inst[j+1] && '9' >= inst[j+1] ){

					arg = 10 * arg + (inst[j+1] - '0');
					j++;
					n++;
				}

				i += n;

			}  
		}				
	}	

	/*____________________opCode____________________*/

	if(strcmp(operation,"ADD") == 0) {

		opCode = 32;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"ADDI") == 0) {

		opCode = 8;

		res = (opCode << 26) | (r[1] << 21) | (r[0] << 16)  | arg;

	}

	if(strcmp(operation,"AND") == 0) {

		opCode = 36;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"BEQ") == 0) {

		opCode = 4;

		res = (opCode << 26) | (r[1] << 21) | (r[0] << 16)  | arg;
	
	}

	if(strcmp(operation,"BGTZ") == 0) {

		opCode = 7;

		res = (opCode << 26) |  (r[0] << 21) | arg;

	}

	if(strcmp(operation,"BLEZ") == 0) {

		opCode = 6;

		res = (opCode << 26) |  (r[0] << 21) | arg;

	}

	if(strcmp(operation,"BNE") == 0) {

		opCode = 5;

		res = (opCode << 26) |  (r[0] << 21) | (r[1] << 16) | arg;

	}

	if(strcmp(operation,"DIV") == 0) {

		opCode = 26;

		res = (r[1] << 21) | (r[2] << 16) | opCode;
	
	}

	if(strcmp(operation,"J") == 0) {

		opCode = 2;

		res = (opCode << 26) | arg;
	
	}

	if(strcmp(operation,"JAL") == 0) {

		opCode = 3;

		res = (opCode << 26) | arg;
	
	}

	if(strcmp(operation,"JR") == 0) {

		opCode = 8;

		res = (r[0] << 21) | opCode;
	
	}

	if(strcmp(operation,"LUI") == 0) {

		opCode = 15;

		res = (opCode << 26) |  (r[0] << 16) | arg;

	}

	if(strcmp(operation,"LW") == 0) {

		opCode = 35; 

		res = (opCode << 26) | (r[1] << 21) | (r[0] << 16) | arg;

	}

	if(strcmp(operation,"MFHI") == 0) {

		opCode = 16;

		res = (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"MFLO") == 0) {

		opCode = 18;

		res = (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"MULT") == 0) {

		opCode = 24;

		res = (r[0] << 21) | (r[1] << 16) | opCode;

	}

	if(strcmp(operation,"NOP") == 0) {

		opCode = 0;

		res = 0;

	}

	if(strcmp(operation,"OR") == 0) {

		opCode = 37;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"ROTR") == 0) {

		opCode = 2;

		res = (r[1] << 16) | (r[0] << 11) | (arg << 6);

	}

	if(strcmp(operation,"SLL") == 0) {

		opCode = 0;

		res = (r[1] << 16) | (r[0] << 11) | (arg << 6);

	}

	if(strcmp(operation,"SLT") == 0) {

		opCode = 42;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"SRL") == 0) {

		opCode = 2;

		res = (r[1] << 16) | (r[0] << 11) | arg << 6 | opCode;

	}

	if(strcmp(operation,"SUB") == 0) {

		opCode = 34;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	if(strcmp(operation,"SW") == 0) {

		opCode = 43;

		res = (opCode << 26) | (r[1] << 21) | (r[0] << 16) | arg;

	}

	if(strcmp(operation,"SYSCALL") == 0) {

		opCode = 12;

		res = (arg << 6) | opCode;

	}

	if(strcmp(operation,"XOR") == 0) {

		opCode = 38;

		res = (r[1] << 21) | (r[2] << 16) | (r[0] << 11) | opCode;

	}

	return res;

}

int fileCompile(char file[], char * fileName){

	FILE *fileI;
	FILE *fileC;
	
	char instruction[100];
	char name[100];
	
	int inst;
	int i = 0;

	/*________compile file name_________*/

	strcpy(name,"");

	while(file[i] != '.' && i < strlen(file)){

		sprintf(name,"%s%c",name,file[i]);
		i++;
			

	}

	sprintf(name,"%s.comp",name);

	printf("fileName : %s\n",name); /* debug <[°_°]>  */

	/*	strcpy(fileName,name); ?????? */


	/*________file opening____________*/


	fileI = fopen(file, "r");

	remove(name);
	fileC = fopen(name, "w+");

	if(fileI == NULL){

		perror("Instructions file error\n");
		return -1;

	}

	if(fileC == NULL){

		perror("Compile file error\n");
		return -1;

	}

	/*________ instructions compilation___________*/
	
	while(fgets(instruction, 60 , fileI) != NULL){

		inst = compile(instruction);

		if(-1 != inst){

			fprintf(fileC,"%d\n",inst);
/*			fprintf(fileC,"%d\n",inst);*/

		}
			
	}

	/*_________file closing ____________________*/

	fclose(fileI);
	fclose(fileC);


	return 0;

}

