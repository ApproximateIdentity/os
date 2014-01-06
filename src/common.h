// common.h -- Defines typedefs and some global functions.
//             From JamesM's kernel development tutorials.

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.

void
outb(uint16_t port, uint8_t value);

uint8_t
inb(uint16_t port);

uint16_t
inw(uint16_t port);

void
memcpy(uintptr_t dest, uintptr_t src, uint32_t len);

void
memset(uintptr_t dest, uint8_t val, uint32_t len);

int
strcmp(char *str1, char *str2);

char
*strcpy(char *dest, const char *src);

char
*strcat(char *dest, const char *src);
