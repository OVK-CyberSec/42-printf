#include "ft_printf.h"
#include <unistd.h>
# include <stdarg.h>
#include <stdint.h>
#include <limits.h>

int printf_format(char specifer, va_list ap);

int  ft_printf(const char *str, ...)
{
    va_list ap;
    int     count;

    va_start(ap, str);
    count = 0;
    while ((*str))
    {
        if ( *str == '%')
            count += printf_format(*(++str), ap);
        else
            count += write(1, str, 1);
        str++;
    }
    va_end(ap);
    return count;
}
/*
int main()
{
    int count;

    count = ft_printf("Hello %s\n", "John");
    printf(" %p %p ", 0, 0);
    ft_printf("%x\n", 42);
}
*/