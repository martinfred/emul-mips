all : main.o compiler.o memory.o
	gcc -o emul-mips main.o compiler.o memory.o

main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o

compiler.o : compiler.c
	gcc -c compiler.c -Wall -ansi -pedantic -o compiler.o

memory.o: memory.c
	gcc -c memory.c -Wall -ansi -pedantic -o memory.o
