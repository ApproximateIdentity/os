TARGET=/home/thomas/osDev/opt/cross/bin/i586-elf

all: myos.bin

myos.bin: boot.o kernel.o monitor.o
	$(TARGET)-gcc -T linker.ld -o myos.bin \
		-ffreestanding -O2 -nostdlib \
		boot.o monitor.o kernel.o -lgcc

kernel.o: kernel.c monitor.h
	$(TARGET)-gcc -c kernel.c -o kernel.o \
		-std=gnu99 -ffreestanding -O2 -Wall -Wextra

monitor.o: monitor.c monitor.h
	$(TARGET)-gcc -c monitor.c -o monitor.o \
		-std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o: boot.s
	$(TARGET)-as boot.s -o boot.o

clean:
	rm *.o myos.bin
