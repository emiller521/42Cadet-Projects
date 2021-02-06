/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 11:12:00 by elmiller          #+#    #+#             */
/*   Updated: 2019/05/04 11:12:04 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_map(int num)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * num);
	while (i < num)
		grid[i++] = (char*)malloc(num + 1);
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num + 1)
		{
			if (j == num)
				grid[i][j] = '\0';
			else
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

char	**initial_map(int num)
{
	char	**map;

	if (num < 2)
		map = make_map(2);
	else if (num < 3)
		map = make_map(3);
	else if (num < 5)
		map = make_map(4);
	else if (num < 7)
		map = make_map(5);
	else if (num < 10)
		map = make_map(6);
	else if (num < 13)
		map = make_map(7);
	else if (num < 17)
		map = make_map(8);
	else if (num < 21)
		map = make_map(9);
	else if (num < 26)
		map = make_map(10);
	else
		map = make_map(11);
	return (map);
}
