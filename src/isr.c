//
// isr.c -- High level interrupt service routines and interrupt request handlers.
//          Part of this code is modified from Bran's kernel development tutorials.
//          Rewritten for JamesM's kernel development tutorials.

#include <stdint.h>

#include "isr.h"
#include "monitor.h"

//typedef struct registers {
    //uint32_t ds;                  // Data segment selector
    //uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    //uint32_t int_no, err_code;    // Interrupt number and error code (if applicable)
    //uint32_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
//} registers_t;

// This gets called from our ASM interrupt handler stub.
void
isr_handler(registers_t regs) {
    uint32_t ds = regs.ds;
    uint32_t edi = regs.edi;
    uint32_t esi = regs.esi;
    uint32_t ebp = regs.ebp;
    uint32_t esp = regs.esp;
    uint32_t ebx = regs.ebx;
    uint32_t edx = regs.edx;
    uint32_t ecx = regs.ecx;
    uint32_t eax = regs.eax;
    uint32_t eip = regs.eip;
    uint32_t cs = regs.cs;
    uint32_t eflags = regs.eflags;
    uint32_t useresp = regs.useresp;
    uint32_t ss = regs.ss;
/*void
isr_handler(void) {*/
    terminal_writestring("received interrupt\n");
    //monitor_write("recieved interrupt: ");
    //monitor_write_dec(regs.int_no);
    //monitor_put('\n');
}
