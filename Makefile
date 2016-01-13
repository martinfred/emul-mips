#Projet emul-mips
#MAKEFILE

#Martin FRAY
#Quentin FRITAYRE

#Grenoble INP - esisar
#P2018

#Valence
#13 janvier 2016


all : main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o save.o
	gcc -o emul-mips main.o compiler.o display.o registers.o controlUnit.o alu.o memory.o save.o

main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o

alu.o : alu.c
	gcc -c alu.c -Wall -ansi -pedantic -o alu.o

controlUnit.o : controlUnit.c
	gcc -c controlUnit.c -Wall -ansi -pedantic -o controlUnit.o

compiler.o : compiler.c
	gcc -c compiler.c -Wall -ansi -pedantic -o compiler.o

display.o : display.c
	gcc -c display.c -Wall -ansi -pedantic -o display.o

memory.o : memory.c
	gcc -c memory.c -Wall -ansi -pedantic -o memory.o

registers.o : registers.c
	gcc -c registers.c -Wall -ansi -pedantic -o registers.o

save.o : save.c
	gcc -c save.c -Wall -ansi -pedantic -o save.o



