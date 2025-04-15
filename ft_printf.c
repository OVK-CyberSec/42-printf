#include "ft_printf.h"

int  ft_printf(const char *str, ...)
{
    va_list ap;
    int     count;

    va_start(ap, str);
    count = 0;
    while ((*str))
    {
        if ( *str == '%')
            count += print_format(*(++str), ap);
        else
            count += write(1, str, 1);
            str++;
    }
    va_end(ap);
    return count;
}