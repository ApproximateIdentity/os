//
// isr.h -- Interface and structures for high level interrupt service routines.
//          Part of this code is modified from Bran's kernel development
//          tutorials. Rewritten for JamesM's kernel development tutorials.
//

struct isr_error {
    uint32_t int_no;
    uint32_t err_code;
} __attribute__((packed));
