#include "ft_printf.h"

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> 

int print_ptr(void *ptr) 
{
    uintptr_t addr = (uintptr_t)ptr;
    int count = 0;

    count += write(1, "0x", 2);
    char hex[16];
    char *digits = "0123456789abcdef";
    int i = 0;

    if (addr == 0) {
        count += write(1, "(nil)", 5);
        return count;
    }

    while (addr) {
        hex[i++] = digits[addr % 16];
        addr /= 16;
    }

    while (i--) {
        count += write(1, &hex[i], 1);
    }

    return count;
}