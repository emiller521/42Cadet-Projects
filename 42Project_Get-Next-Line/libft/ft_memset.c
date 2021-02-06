/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:23:30 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/10 23:24:59 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *dest, int c, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = dest;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (dest);
}
