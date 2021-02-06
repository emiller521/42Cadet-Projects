#ifndef B_PRINTF_H
# define B_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/Libft/libft.h"

void	ft_printchar(int i, int *len_ptr);
void	ft_printstr(char *str, int *len_ptr);
void	ultoa_base(unsigned long num, int base, int *len_ptr);
void	ft_printint(int i, int *len_ptr);
void	format(va_list arg, char c, int *len_ptr);
int		b_printf(const char *s, ...);
int	    main(int ac, char **av);

#endif
