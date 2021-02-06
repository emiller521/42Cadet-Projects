/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:41:12 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/06 02:21:37 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(s) + 1;
	while (count > 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
		count--;
	}
	return (NULL);
}
