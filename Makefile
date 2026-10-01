run: compile
	./main.o

compile: main.c
	gcc -o main.o -std=c89 main.c -lm
