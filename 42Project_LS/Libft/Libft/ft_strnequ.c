/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:47:52 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/10 23:47:59 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		i = 0;
		while (i < n && *s1 && *s2)
		{
			if (*s1 != *s2)
				return (0);
			i++;
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}
