#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int ft_printf(const char *str, ...);
void print_hex(uintptr_t value);
int print_ptr(void *ptr);
int printf_format(char specifer, va_list ap);
int print_char(int c);
int print_string(char *str);
int print_digit(long nbr, int base);
int	ft_ptr_len(uintptr_t num);
void	ft_putchar_fd(char c, int fd);

#endif