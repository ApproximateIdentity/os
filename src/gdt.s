#
# Gdt.s -- contains global descriptor table and interrupt descriptor table
#          setup code.
#          Based on code from Bran's kernel development tutorials.
#          Rewritten for JamesM's kernel development tutorials.
#.section data <--- Apparently that fucks shit up

#.section text <--- Apparently that fucks shit up too

.globl gdt_flush
gdt_flush:
 movl 4(%esp),  %eax  # Get the pointer to the GDT, passed as a parameter.
 lgdt (%eax)             # Load the new GDT pointer

 mov  $0x10,    %ax   # 0x10 is the offset in the GDT to our data segment
 mov  %ax,      %ds   # Load all data segment selectors
 mov  %ax,      %es
 mov  %ax,      %fs
 mov  %ax,      %gs
 mov  %ax,      %ss
 jmp  $0x08,    $flush   # 0x08 is the offset to our code segment: Far jump!
flush:
 ret

.globl idt_flush
 idt_flush:
 mov  4(%esp),   %eax  # Get the pointer to the IDT, passed as a parameter. 
 lidt (%eax)              # Load the IDT pointer.
 ret
