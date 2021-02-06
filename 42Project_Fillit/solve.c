/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:47:49 by cdimitro          #+#    #+#             */
/*   Updated: 2019/05/04 11:02:09 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtrack(t_tetra list[MAX_TETRA], char **map, int i, int size)
{
	int		x;
	int		y;

	if (list[i].name == (char)NULL)
		return (1);
	x = 0;
	y = 0;
	while (y < size)
	{
		while (map[y][x] != '\0')
		{
			if (can_place(list[i], map, y, x))
			{
				map = place_tetra(list[i], map, y, x);
				if (backtrack(list, map, i + 1, size))
					return (1);
				else
					map = remove_tetra(map, list[i].name, size);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	**resize_map(char **map)
{
	int	i;
	int num;

	i = 0;
	num = ft_strlen(map[0]);
	while (i < num)
	{
		free(map[i]);
		i++;
	}
	free(map);
	num += 1;
	map = make_map(num);
	return (map);
}

char	**fillit(char **map, t_tetra list[MAX_TETRA], int size)
{
	while (!backtrack(list, map, 0, size))
	{
		map = resize_map(map);
		size++;
	}
	return (map);
}

void	finish(t_tetra list[MAX_TETRA], int num)
{
	char	**grid;
	int		size;

	grid = initial_map(num);
	size = ft_strlen(grid[0]);
	grid = fillit(grid, list, size);
	print_map(grid);
}

void	print_map(char **map)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_strlen(map[0]);
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
