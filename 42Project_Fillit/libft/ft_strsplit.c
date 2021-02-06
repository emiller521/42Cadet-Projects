/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:43:24 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/11 22:40:03 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	k = ft_word_count(str, c);
	if (!(res = (char **)malloc(sizeof(res) * (ft_word_count(str, c) + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < k && str[i])
	{
		res[j] = ft_word_delim(str, c, &i);
		j++;
	}
	res[j] = NULL;
	return (res);
}
