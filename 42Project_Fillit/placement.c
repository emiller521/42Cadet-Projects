/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:49:13 by cdimitro          #+#    #+#             */
/*   Updated: 2019/05/04 11:00:32 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		placement_check(t_tetra tetra, char **map, int y, int x)
{
	int len;

	len = ft_strlen(map[0]) - 1;
	if ((x + tetra.x[1] < 0) || (y + tetra.y[1] < 0) || (x + tetra.x[2] < 0) ||
		(y + tetra.y[2] < 0) || (x + tetra.x[3] < 0) || (y + tetra.y[3] < 0) ||
		(x + tetra.x[1] > len) || (y + tetra.y[1] > len) ||
		(x + tetra.x[2] > len) || (y + tetra.y[2] > len) ||
		(x + tetra.x[3] > len) || (y + tetra.y[3] > len))
		return (0);
	return (1);
}

char	**place_tetra(t_tetra tetra, char **map, int y, int x)
{
	map[y][x] = tetra.name;
	map[y + tetra.y[1]][x + tetra.x[1]] = tetra.name;
	map[y + tetra.y[2]][x + tetra.x[2]] = tetra.name;
	map[y + tetra.y[3]][x + tetra.x[3]] = tetra.name;
	return (map);
}

int		can_place(t_tetra tetra, char **map, int y, int x)
{
	if (!placement_check(tetra, map, y, x))
		return (0);
	if ((map[y][x] == '.') &&
		(map[y + tetra.y[1]][x + tetra.x[1]] == '.') &&
		(map[y + tetra.y[2]][x + tetra.x[2]] == '.') &&
		(map[y + tetra.y[3]][x + tetra.x[3]] == '.'))
		return (1);
	return (0);
}

char	**remove_tetra(char **map, char name, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == name)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}
