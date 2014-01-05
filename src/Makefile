SOURCES=boot.o kernel.o monitor.o common.o descriptor_tables.o \
		isr.o interrupt.o gdt.o timer.o

TARGET=/home/thomas/osDev/opt/cross/bin/i586-elf

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib -lgcc
CC=$(TARGET)-gcc
AS=$(TARGET)-as

myos.bin: $(SOURCES)
	$(TARGET)-gcc -o myos.bin $(SOURCES) $(LDFLAGS)

clean:
	rm *.o myos.bin
