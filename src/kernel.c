#include "monitor.h"

void
kernel_main()
{
	terminal_initialize();
	terminal_writestring("Hello, kernel World!\nHello, world again!");
}
