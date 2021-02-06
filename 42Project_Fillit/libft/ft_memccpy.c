/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:20:35 by cdimitro          #+#    #+#             */
/*   Updated: 2019/02/27 01:17:16 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*un_dst;
	unsigned char	*un_src;

	i = 0;
	un_dst = (unsigned char *)dst;
	un_src = (unsigned char *)src;
	while (i < n)
	{
		un_dst[i] = un_src[i];
		if (un_src[i] == (unsigned char)c)
		{
			un_dst[i] = un_src[i];
			i++;
			return (&dst[i]);
		}
		i++;
	}
	return (NULL);
}
