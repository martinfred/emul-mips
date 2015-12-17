all : main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o
	gcc -o emul-mips main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o

main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o

compiler.o : compiler.c
	gcc -c compiler.c -Wall -ansi -pedantic -o compiler.o

display.o : display.c
	gcc -c display.c -Wall -ansi -pedantic -o display.o

registers.o : registers.c
	gcc -c registers.c -Wall -ansi -pedantic -o registers.o

controlUnit.o : controlUnit.c
	gcc -c controlUnit.c -Wall -ansi -pedantic -o controlUnit.o

alu.o : alu.c
	gcc -c alu.c -Wall -ansi -pedantic -o alu.o

memory.o: memory.c
	gcc -c memory.c -Wall -ansi -pedantic -o memory.o
