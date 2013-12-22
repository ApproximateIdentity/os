TARGET=/home/thomas/osDev/opt/cross/bin/i586-elf

all: myos.bin kernel.o boot.o

myos.bin:  linker.ld boot.o kernel.o
	$(TARGET)-gcc -T linker.ld -o myos.bin \
		-ffreestanding -O2 -nostdlib \
		boot.o kernel.o -lgcc

kernel.o: kernel.c
	$(TARGET)-gcc -c kernel.c -o kernel.o \
		-std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o: boot.s
	$(TARGET)-as boot.s -o boot.o

clean:
	rm *.o myos.bin
