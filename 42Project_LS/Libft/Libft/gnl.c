/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:12:01 by elmiller          #+#    #+#             */
/*   Updated: 2019/04/02 21:26:10 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				ft_new_line(char **array, char **line)
{
	char	*n;
	char	*tmp;

	if ((*array)[0] == '\0')
		return (0);
	tmp = ft_strdup(*array);
	ft_memdel((void**)array);
	if ((n = ft_strchr(tmp, '\n')))
	{
		*n = '\0';
		*line = ft_strdup(tmp);
		*array = ft_strdup(n + 1);
		ft_memdel((void**)&tmp);
	}
	else
	{
		*line = tmp;
		ft_memdel((void**)array);
	}
	return (1);
}

int				reader(int fd, char *buffer)
{
	int		read_bytes;

	if ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
		return (read_bytes);
	else if ((read_bytes = read(fd, buffer, 0)) == 0)
		return (0);
	else
		return (-1);
}

int				get_next_line(const int file_d, char **line)
{
	static char *str[FD_LIMIT];
	char		buffer[BUFF_SIZE + 1];
	int			bytes;
	char		*tmp;

	if (file_d < 0 || !line || file_d > FD_LIMIT)
		return (-1);
	if (!str[file_d])
		str[file_d] = ft_strnew(0);
	if ((read(file_d, buffer, 0) < 0))
		return (-1);
	while (!ft_strchr(str[file_d], '\n'))
	{
		bytes = reader(file_d, buffer);
		buffer[bytes] = '\0';
		if (bytes == 0)
			break ;
		tmp = ft_strjoin(str[file_d], buffer);
		free(str[file_d]);
		str[file_d] = ft_strdup(tmp);
		free(tmp);
	}
	return (ft_new_line(&str[file_d], line));
}
