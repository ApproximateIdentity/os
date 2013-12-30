TARGET=/home/thomas/osDev/opt/cross/bin/i586-elf

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib -lgcc


all: myos.bin

myos.bin: boot.o kernel.o monitor.o descriptor_tables.o common.o interrupt.o gdt.o isr.o
	$(TARGET)-gcc -o myos.bin boot.o monitor.o kernel.o \
		descriptor_tables.o interrupt.o common.o gdt.o isr.o $(LDFLAGS)

kernel.o: kernel.c monitor.h
	$(TARGET)-gcc -c kernel.c -o kernel.o $(CFLAGS)

monitor.o: monitor.c monitor.h
	$(TARGET)-gcc -c monitor.c -o monitor.o $(CFLAGS)

descriptor_tables.o: descriptor_tables.c descriptor_tables.c
	$(TARGET)-gcc -c descriptor_tables.c -o descriptor_tables.o $(CFLAGS)

common.o: common.c common.c
	$(TARGET)-gcc -c common.c -o common.o $(CFLAGS)

isr.o: isr.c isr.h
	$(TARGET)-gcc -c isr.c -o isr.o $(CFLAGS)

boot.o: boot.s
	$(TARGET)-as boot.s -o boot.o

interrupt.o: interrupt.s
	$(TARGET)-as interrupt.s -o interrupt.o

gdt.o: gdt.s
	$(TARGET)-as gdt.s -o gdt.o

clean:
	rm *.o myos.bin a.out
