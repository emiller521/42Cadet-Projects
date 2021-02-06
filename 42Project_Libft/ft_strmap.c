/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:56:00 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/11 20:31:06 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *str, char (*f)(char))
{
	char	*new;
	size_t	i;

	i = 0;
	if (str == NULL || f == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = f(str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
