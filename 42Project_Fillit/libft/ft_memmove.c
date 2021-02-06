/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:38:42 by cdimitro          #+#    #+#             */
/*   Updated: 2019/02/27 00:24:45 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*un_dst;
	unsigned char	*un_src;

	if (src == dst)
		return (dst);
	un_dst = (unsigned char*)dst;
	un_src = (unsigned char*)src;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			un_dst[i] = un_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			un_dst[i] = un_src[i];
			i++;
		}
	}
	return (dst);
}
