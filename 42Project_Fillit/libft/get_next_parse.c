/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:03:19 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/15 09:32:13 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_parse(char **data, char **line)
{
	char	*temp;
	int		nl;

	nl = 0;
	temp = ft_strdup(*data);
	ft_strdel(data);
	while (temp[nl] != '\n' && temp[nl] != '\0')
		nl++;
	if (temp[nl] == '\n')
	{
		temp[nl] = '\0';
		*line = ft_strdup(temp);
		*data = ft_strdup(&temp[nl + 1]);
		free(temp);
	}
	else
	{
		*line = ft_strdup(temp);
		free(temp);
	}
	return (1);
}
