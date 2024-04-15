all: myos.bin

myos.bin: boot.o main.o
	ld -o bin/myos.bin -Ttext 0x7C00 --oformat=binary boot.o main.o

boot.o:
	nasm -f elf src/boot.asm -o boot.o

main.o:
	gcc -ffreestanding -c src/main.c -o main.o

clean:
	rm -f *.o bin/myos.bin
