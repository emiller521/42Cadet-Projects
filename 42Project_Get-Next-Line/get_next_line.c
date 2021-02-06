/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:12:01 by elmiller          #+#    #+#             */
/*   Updated: 2019/04/04 11:09:17 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				ft_new_line(char **array, char **line)
{
	char	*n;
	char	*tmp;

	if ((*array)[0] == '\0')//If the first char read on the array is empty, return(0)
		return (0);
	tmp = ft_strdup(*array);//Dupicate all information found in the **array 
	ft_memdel((void**)array);//Delete original copy of **array
	if ((n = ft_strchr(tmp, '\n')))//Looking for new line char on *tmp
	{
		*n = '\0';//If new line is found, set that char to end of line
		*line = ft_strdup(tmp);//Set everything found BEFORE nee line char into *line
		*array = ft_strdup(n + 1);//Duplicate everything found after new line into *array 
		ft_memdel((void**)&tmp);//Delete the original copy of tmp
	}
	else
	{
		*line = tmp;//If no new line, is found set everything in tmp into *line
		ft_memdel((void**)array);//Delete the original copy of array
	}
	return (1);
}

int				reader(int fd, char *buffer)
{
	int		read_bytes;

	if ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)//If your reading bytes
		return (read_bytes);//Return the number of bytes read 
	else if ((read_bytes = read(fd, buffer, 0)) == 0)//If there are no bytes to read, reader function returns 0
		return (0);
	else
		return (-1);//If nothing is done, return an error
}

int				get_next_line(const int file_d, char **line)
{
	static char *str[FD_LIMIT];
	char		buffer[BUFF_SIZE + 1];
	int			bytes;
	char		*tmp;

	if (file_d < 0 || !line || file_d > FD_LIMIT)
		return (-1);
	if (!str[file_d])//If file descriptor is empty
		str[file_d] = ft_strnew(0);//File descriptor is equal to a new string 
	if ((read(file_d, buffer, 0) < 0))//If there is nothing to read
		return (-1);//Return error
	while (!ft_strchr(str[file_d], '\n'))//While you haven't found a new line yet
	{
		bytes = reader(file_d, buffer);//Bytes is equal to number of bytes read
		buffer[bytes] = '\0';
		if (bytes == 0)//If there are no more bytes to be read
			break ;
		tmp = ft_strjoin(str[file_d], buffer);//Put file descriptor and buffer into tmp
		free(str[file_d]);
		str[file_d] = ft_strdup(tmp);//File descriptor equal to duplicater of tmp
		free(tmp);
	}
	return (ft_new_line(&str[file_d], line));/
}
