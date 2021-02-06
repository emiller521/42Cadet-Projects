/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:38:26 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/05 15:04:42 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*data[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			count;

	if (line && fd >= 0 && BUFF_SIZE > 0 && read(fd, buff, 0) > -1)
	{
		if (data[fd] == NULL)
			data[fd] = (char*)ft_memalloc(1);
		while (!ft_strchr(data[fd], '\n'))
		{
			count = reader(fd, buff);
			if (count == 0)
				break ;
			buff[count] = '\0';
			temp = ft_strjoin(data[fd], buff);
			free(data[fd]);
			data[fd] = ft_strdup(temp);
			free(temp);
		}
		if (count == 0 && data[fd][0] == '\0')
			return (0);
		return (get_next_parse(&data[fd], line));
	}
	return (-1);
}
