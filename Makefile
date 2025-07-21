all: main

main: main.c acceleration.o
	@gcc -O2 -o main main.c acceleration.o -lm

acceleration.o: acceleration.asm
	@nasm -f elf64 acceleration.asm -o acceleration.o

clean:
	@rm -f *.o main
