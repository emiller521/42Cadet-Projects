/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 10:59:36 by elmiller          #+#    #+#             */
/*   Updated: 2019/05/04 10:59:42 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		size_of_file(char *arg)
{
	int		fd;
	int		count;
	char	buf[BUFF_SIZE + 1];

	fd = open(arg, O_RDONLY);
	count = read(fd, buf, BUFF_SIZE);
	close(fd);
	return (count);
}

int		find_num_tetra(char *str)
{
	int num;
	int	size;

	size = size_of_file(str);
	if (size == 0)
		return (1);
	else
		num = (size / 21) + 1;
	return (num);
}

int		main(int ac, char **av)
{
	int		num;
	t_tetra list[MAX_TETRA];
	char	a;
	int		fd;

	if (ac == 2)
	{
		ac = 0;
		a = 'A';
		num = find_num_tetra(av[1]);
		fd = open(av[1], O_RDONLY);
		while (ac < num)
		{
			av = get_next_tetra(fd);
			list[ac] = get_coords(av);
			list[ac] = reset_coords(list[ac]);
			list[ac++].name = a;
			a++;
			free(av);
		}
		close(fd);
		finish(list, num);
	}
	else
		ft_putstr("usage: fillit input_file\n");
}
