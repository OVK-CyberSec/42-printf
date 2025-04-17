#include "ft_printf.h"
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

int print_char(int c)
{
    return (write(1, &c, 1));
}

int print_string(char *str)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        print_char((int)*str);
        count++;
        str++;
    }
    return count;
}

int print_digit(long nbr, int base)
{
    int count;
    char *numbers;

    numbers = "0123456789abcdef";
    if (nbr < 0)
    {
        write(1, "-", 1);
        return print_digit(-nbr, base) + 1;
    }
    else if (nbr < base)
        return (print_char(numbers[nbr]));
    else
    {
        count = print_digit(nbr / base, base);
        return (count + print_digit(nbr % base, base));
    }
}

int print_digit_upper(unsigned int nbr, unsigned int base)
{
    int count = 0;
    char *numbers = "0123456789ABCDEF";

    if (nbr < base)
        count += print_char(numbers[nbr]);
    else
    {
        count += print_digit_upper(nbr / base, base);
        count += print_digit_upper(nbr % base, base);
    }
    return count;
}
