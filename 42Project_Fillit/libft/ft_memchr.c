/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:22:38 by cdimitro          #+#    #+#             */
/*   Updated: 2019/02/22 21:53:31 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*b;
	unsigned char	a;

	i = 0;
	b = (unsigned char*)s;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
		n--;
	}
	return (NULL);
}
