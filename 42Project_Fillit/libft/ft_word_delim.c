/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 04:25:24 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/11 22:42:29 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_word_delim(char const *s, char c, int *i)
{
	char	*res;
	int		k;

	if (!(res = (char *)malloc(ft_strlen(s))))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		res[k] = s[*i];
		k++;
		*i += 1;
	}
	res[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (res);
}
