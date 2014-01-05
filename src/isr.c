//
// isr.c -- High level interrupt service routines and interrupt request
//          handlers. Part of this code is modified from Bran's kernel
//          development tutorials. Rewritten for JamesM's kernel development
//          tutorials.

#include <stdint.h>

#include "isr.h"
#include "monitor.h"
#include "common.h"

isr_t interrupt_handlers[256];

void
register_interrupt_handler(uint8_t n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

// This gets called from our ASM interrupt handler stub.
void
isr_handler(err_t *err) {
    terminal_writestring("received interrupt: ");
    terminal_writenum(err->int_no);
    terminal_writestring(", ");
    terminal_writenum(err->err_code);
    terminal_writestring("\n");
}

void
irq_handler(err_t *err) {
    // Send an EOI signal to the PICs
    // If this interrupt involved slave, reset it.
    if (err->int_no >= 40) {
        // Send reset signal to slave
        outb(0xA0, 0x20);
    }
    // Send reset signal to master
    outb(0x20, 0x20);

    if (err->int_no != 0) {
        isr_t handler = interrupt_handlers[err->int_no];
        handler(err);
    }
}
