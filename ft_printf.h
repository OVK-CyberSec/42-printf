#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int  ft_printf(const char *str, ...);
int printf_format(char specifer, va_list ap);
int print_char(int c);
int print_string(char *str);
int print_digit(long nbr, int base);


#endif