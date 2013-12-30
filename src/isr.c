//
// isr.c -- High level interrupt service routines and interrupt request handlers.
//          Part of this code is modified from Bran's kernel development tutorials.
//          Rewritten for JamesM's kernel development tutorials.

#include <stdint.h>

#include "isr.h"
#include "monitor.h"

// This gets called from our ASM interrupt handler stub.
void
isr_handler(registers_t * regs) {
    terminal_writestring("received interrupt: ");
    terminal_writenum(regs->int_no);
    terminal_writestring(", ");
    terminal_writenum(regs->err_code);
    terminal_writestring("\n");
}
