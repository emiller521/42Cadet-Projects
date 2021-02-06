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