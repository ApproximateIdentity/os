#include <stdint.h>

#include "monitor.h"
#include "descriptor_tables.h"

void
kernel_main()
{
    init_descriptor_tables();
	terminal_initialize();
	terminal_writestring("Hello, kernel World!\n");
    terminal_writestring("Hello, world again!\n");
    asm volatile ("int $0x3");
    asm volatile ("int $0x4");
}
