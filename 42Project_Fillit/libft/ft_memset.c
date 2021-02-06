/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:47:13 by cdimitro          #+#    #+#             */
/*   Updated: 2019/02/22 21:55:17 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*tmp;
	unsigned char	a;

	i = 0;
	tmp = (char*)b;
	a = (unsigned char)c;
	while (len > 0)
	{
		tmp[i] = a;
		i++;
		len--;
	}
	return (b);
}
