#include "b_printf.h"

void	format(va_list arg, char c, int *lenptr)
{
	if (c == 'c')
		ft_printchar(va_arg(arg, int), lenptr);
	else if (c == 's')
		ft_printstr(va_arg(arg, char *), lenptr);
	else if (c == 'd' || c == 'i')
		ft_printint(va_arg(arg, int), lenptr);
	else if (c == 'u')
		ultoa_base(va_arg(arg, unsigned int), 10, lenptr);
	else if (c == 'p')
	{
		ft_printstr("0x", lenptr);
		ultoa_base(va_arg(arg, unsigned long), 16, lenptr);
	}
	else if (c == 'o')
		ultoa_base(va_arg(arg, unsigned int), 8, lenptr);
	else if (c == 'x')
		ultoa_base(va_arg(arg, unsigned int), 16, lenptr);
	else if (c == '%')
		ft_printchar((int)'%', lenptr);
}

int		b_printf(const char *s, ...)
{
	int		len;
	int		*lenptr;
	va_list	arg;
	int		i;

	i = 0;
	len = 0;
	lenptr = &len;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_printchar((int)s[i], lenptr);
		else
		{
			i++;
			format(arg, s[i], lenptr);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
#include <stdio.h>

int main(int ac, char **av)
{
	int j;
	int i;

	i = 0;
	j = 1;
    while (j < ac)
    {
		//j = 1;
        if(av[j][i] == 'c')
        {
            b_printf("Char Test1->%c\n", 'E');
            b_printf("Char Test2->%c\n", 'L');
            b_printf("Char Test3->%c\n", 'I');
            printf("Printf->%c\n", 'E');
            printf("Printf->%c\n", 'L');
            printf("Printf->%c\n", 'I');
        }
        if(av[j][i] == 's')
        {
            b_printf("String Test 1->%s\n", "Hello");
            b_printf("String Test 2->%s\n", "&123");
            b_printf("String Test 3->%s\n", "~testing");
            printf("Printf->%s\n", "Hello");
            printf("Printf->%s\n", "&123");
            printf("Printf->%s\n", "~testing");
        }
        if(av[j][i] == 'd')
        {
            b_printf("Digit Test 1->%d\n", 42);
            b_printf("Digit Test 2->%d\n", 32);
            b_printf("Int Test 1->%i\n", 22);
            b_printf("Int Test 2->%i\n", 555);
            printf("Printf Int->%i\n", 22);
            printf("Printf Int->%i\n", 555);
            printf("Printf Digit->%d\n", 42);
            printf("Printf Digit->%d\n", 32);
		}
		write(1, "\n", 1);
		j++;
    }
	write(1, "\n", 1);
	return(0);
}