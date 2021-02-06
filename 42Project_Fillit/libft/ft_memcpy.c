/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:53 by cdimitro          #+#    #+#             */
/*   Updated: 2019/02/24 20:05:59 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*ndst;
	char	*nsrc;

	i = 0;
	ndst = (char*)dst;
	nsrc = (char*)src;
	while (n-- > 0)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (dst);
}
