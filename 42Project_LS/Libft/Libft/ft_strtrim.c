/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:50:11 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/10 23:50:18 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	size_t	start;
	char	*s_p;

	if (s)
	{
		len = 0;
		while (s[len] && (s[len] == '\t' || s[len] == ' ' || s[len] == '\n'))
			len++;
		start = len;
		if (start == (size_t)ft_strlen(s))
			return (ft_strnew(1));
		len = ft_strlen(s);
		len--;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		len++;
		if ((s_p = ft_strsub(s, start, len - start)))
			return (s_p);
		else
			return (NULL);
	}
	return (NULL);
}
