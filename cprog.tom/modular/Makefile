modular : prog15-1.module-1.o prog15-2.module-2.o
	gcc -Wall -o modular prog15-1.module-1.o prog15-2.module-2.o

prog15-1.module-1.o : prog15-1.module-1.c prog15-2.h prog15-2.module-2.c
	gcc -Wall -c prog15-1.module-1.c

prog15-2.module-2.o : prog15-2.h prog15-2.module-2.c
	gcc -Wall -c prog15-2.module-2.c

clean :
	rm prog15-2.module-2.o prog15-1.module-1.o modular
