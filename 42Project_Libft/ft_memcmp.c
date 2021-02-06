/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:48:07 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/11 04:23:30 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *dest, const void *src, size_t num)
{
	unsigned char		*dest1;
	unsigned char		*src1;
	size_t				i;

	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (i < num)
	{
		if (dest1[i] != src1[i])
			return (dest1[i] - src1[i]);
		i++;
	}
	return (0);
}
