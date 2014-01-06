//
// isr.h -- Interface and structures for high level interrupt service routines.
//          Part of this code is modified from Bran's kernel development
//          tutorials. Rewritten for JamesM's kernel development tutorials.
//

struct isr_err {
    uint32_t int_no;
    uint32_t err_code;
} __attribute__((packed));

typedef struct isr_err err_t;

// Enables registration of callbacks for interrupts or IRQs
// For IRQs, to ease confusion, use the #defines above as the
// first parameter.
typedef void (*isr_t)(err_t *err);

void
register_interrupt_handler(uint8_t n, isr_t handler);
