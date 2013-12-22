TARGET=/home/thomas/osDev/opt/cross/bin/i586-elf

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib -lgcc


all: myos.bin

myos.bin: boot.o kernel.o monitor.o
	$(TARGET)-gcc -o myos.bin boot.o monitor.o kernel.o $(LDFLAGS)

kernel.o: kernel.c monitor.h
	$(TARGET)-gcc -c kernel.c -o kernel.o $(CFLAGS)

monitor.o: monitor.c monitor.h
	$(TARGET)-gcc -c monitor.c -o monitor.o $(CFLAGS)

boot.o: boot.s
	$(TARGET)-as boot.s -o boot.o

clean:
	rm *.o myos.bin
