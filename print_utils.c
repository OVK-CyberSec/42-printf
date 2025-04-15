#include "ft_printf.h"

int print_char(int c)
{
    return (write(1, &c, 1));
}

int print_string(char *str)
{
    int count;

    count = 0;
    while(*str)
    {
        print_char((int)*str);
        count++;
        str++;
    }
    return (count);
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