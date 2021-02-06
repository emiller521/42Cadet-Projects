/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:33:10 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/12 10:34:18 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
		if ((s[i] != c) && (w += (s[i] != c && s[i])))
			while (s[i] != c && s[i])
				i++;
		else
			while (s[i] == c && s[i])
				i++;
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		w;
	size_t		len;
	char		**list;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	w = words(s, c);
	if ((list = (char **)malloc(sizeof(*list) * (w + 1))))
		while (j < w && !(len = 0))
		{
			while (s[i] == c && s[i])
				i++;
			while (s[i + len] != c && s[i + len])
				len++;
			if (!(list[j] = ft_strsub(s, i, len)))
				return (NULL);
			i += len;
			j++;
			list[w] = NULL;
		}
	return (list);
}
