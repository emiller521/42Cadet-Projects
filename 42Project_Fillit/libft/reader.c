/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:04:15 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/05 16:42:56 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		reader(const int fd, char *buff)
{
	int count;

	count = read(fd, buff, BUFF_SIZE);
	if (count > 0)
		return (count);
	else if (count == 0)
		return (0);
	else
		return (-1);
}
