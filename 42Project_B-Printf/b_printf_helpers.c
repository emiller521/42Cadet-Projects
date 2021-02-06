#include "b_printf.h"

void	ft_printchar(int i, int *lenptr)
{
	char c;

	c = (char)i;
	write(1, &c, 1);
	*lenptr += 1;
}

void	ft_printstr(char *str, int *lenptr)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (str[i])
			i++;
		write(1, str, i);
	}
	*lenptr += i;
}

void	ultoa_base(unsigned long num, int base, int *lenptr)
{
	char			*tab;
	unsigned long	temp_nbr;
	char			*str;
	int				size;

	tab = "0123456789abcdef";
	temp_nbr = num;
	size = 1;
	while (temp_nbr /= base)
		size++;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return ;
	str[size] = '\0';
	while (size--)
	{
		str[size] = tab[num % base];
		num /= base;
	}
	ft_printstr(str, lenptr);
	free(str);
}

void	ft_printint(int i, int *lenptr)
{
	long l;

	l = i;
	if (l < 0)
	{
		l = -l;
		ft_printchar((int)'-', lenptr);
	}
	ultoa_base(l, 10, lenptr);
}
