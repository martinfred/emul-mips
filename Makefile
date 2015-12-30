all : main.o compiler.o 
	gcc -o emul-mips main.o compiler.o 

main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o

compiler.o : compiler.c
	gcc -c compiler.c -Wall -ansi -pedantic -o compiler.o



