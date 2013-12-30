#include <stdint.h>

#include "monitor.h"
#include "descriptor_tables.h"

void
kernel_main() {
    init_descriptor_tables();
    terminal_initialize();
    asm volatile ("int $0x1");
    asm volatile ("int $0x2");
}
