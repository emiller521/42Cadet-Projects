/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:01:28 by cdimitro          #+#    #+#             */
/*   Updated: 2019/05/04 11:01:22 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_newline(char *line)
{
	if (line[0] != '\0')
		return (0);
	return (1);
}

int		check_char(char **tetra)
{
	int i;
	int j;
	int hash;

	i = 0;
	j = 0;
	hash = 0;
	while (i < MAX_GRID)
	{
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] != '.' && tetra[i][j] != '#')
				return (0);
			else if (tetra[i][j] == '#')
				hash++;
			j++;
		}
		if (j != MAX_GRID)
			return (0);
		j = 0;
		i++;
	}
	if (hash != MAX_GRID)
		return (0);
	return (1);
}

int		add_count(char **tetra, int i, int j)
{
	int count;

	count = 0;
	if (i < 3)
	{
		if (tetra[i + 1][j] == '#')
			count++;
	}
	if (i > 0)
	{
		if (tetra[i - 1][j] == '#')
			count++;
	}
	if (j < 3)
	{
		if (tetra[i][j + 1] == '#')
			count++;
	}
	if (j > 0)
	{
		if (tetra[i][j - 1] == '#')
			count++;
	}
	return (count);
}

int		check_hash(char **tetra)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < MAX_GRID)
	{
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] == '#')
				count += add_count(tetra, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	else
		return (0);
}
