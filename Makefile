#Ceci est un test Martin, et pas un coupe papier car il n'y a pas de livre. Fromage
all : main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o
	gcc -o emul-mips main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o

main.o : main.c compiler.h display.h registers.h controlUnit.h alu.h memory.h
	gcc -c main.c -Wall -ansi -pedantic -o main.o

compiler.o : compiler.c compiler.h
	gcc -c compiler.c -Wall -ansi -pedantic -o compiler.o

display.o : display.c display.h
	gcc -c display.c -Wall -ansi -pedantic -o display.o

registers.o : registers.c registers.h
	gcc -c registers.c -Wall -ansi -pedantic -o registers.o

controlUnit.o : controlUnit.c controlUnit.h
	gcc -c controlUnit.c -Wall -ansi -pedantic -o controlUnit.o

alu.o : alu.c alu.h
	gcc -c alu.c -Wall -ansi -pedantic -o alu.o

memory.o: memory.c memory.h
	gcc -c memory.c -Wall -ansi -pedantic -o memory.o
