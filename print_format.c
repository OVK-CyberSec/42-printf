#include "ft_printf.h"

int printf_format(char specifer, va_list ap)
{
    int count;

    count = 0;
    if (specifer == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifer == 's')
        count += print_string(va_arg(ap, char *));
    else if (specifer == 'd' || specifer == 'i')
        count += printf_digit(va_arg(ap, int), 10);
    else if (specifer == 'x')
        count += print_digit(va_arg(ap, unsigned int), 16);
    else if (specifer == 'X')
        count += print_digit_upper(va_arg(ap, unsigned int), 16);
    else if (specifer == 'p')
        count += print_pointer(va_arg(ap, void *));
    else if (specifer == 'u')
        count += print_digit(va_arg(ap, unsigned int), 10);
    else if (specifer == '%')
        count += print_char('%');
    return count;
}