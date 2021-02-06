/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:48:38 by cdimitro          #+#    #+#             */
/*   Updated: 2019/05/04 10:58:07 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_next_tetra(const int fd)
{
	char	**grid;
	char	*line;
	int		i;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * MAX_GRID);
	while (i < MAX_GRID)
	{
		if (get_next_line(fd, &line) == 1)
			grid[i++] = ft_strdup(line);
		else
			error();
		free(line);
	}
	if (get_next_line(fd, &line) == 1)
		if (!check_newline(line))
			error();
	if (!check_char(grid))
		error();
	if (!check_hash(grid))
		error();
	return (grid);
}

t_tetra	get_coords(char **grid)
{
	t_tetra	tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < MAX_GRID)
	{
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == '#')
			{
				tab.x[k] = j;
				tab.y[k] = i;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

t_tetra	reset_coords(t_tetra tetra)
{
	t_tetra	res;
	int		i;
	int		x_temp;
	int		y_temp;

	i = 1;
	x_temp = tetra.x[0];
	y_temp = tetra.y[0];
	while (i < MAX_GRID)
	{
		res.x[i] = tetra.x[i] - x_temp;
		res.y[i] = tetra.y[i] - y_temp;
		i++;
	}
	res.x[0] = 0;
	res.y[0] = 0;
	return (res);
}
