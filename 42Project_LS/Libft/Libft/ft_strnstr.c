/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 04:16:18 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/11 19:14:59 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *b, const char *l, size_t len)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = (char *)b;
	if (*l == 0)
		return (res);
	while (b[i])
	{
		j = 0;
		while (b[i + j] == l[j] && l[j] && (size_t)(i + j) < len)
			j++;
		if (l[j] == 0)
		{
			res += i;
			return (char *)(res);
		}
		i++;
	}
	return ((char *)NULL);
}
