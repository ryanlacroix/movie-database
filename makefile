movieBase : main.o UI.o list.o
	gcc -o movieBase main.o UI.o list.o

main.o : main.c defs.h
	gcc -c main.c

UI.o : UI.c defs.h
	gcc -c UI.c

list.o : list.c defs.h
	gcc -c list.c
