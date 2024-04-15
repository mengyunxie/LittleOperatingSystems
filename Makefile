all: myos.bin

myos.bin: boot.bin main.o
	ld -o bin/myos.bin -Ttext 0x7C00 --oformat=binary bin/boot.bin main.o

boot.bin:
	nasm -f bin src/boot.asm -o bin/boot.bin

main.o:
	gcc -ffreestanding -c src/main.c -o main.o

clean:
	rm -f *.o *.bin bin/myos.bin
