/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 04:29:04 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/06 04:29:21 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_pos(int n, int count)
{
	char *res;

	if (!(res = (char*)malloc(sizeof(char) * count + 2)))
		return (NULL);
	res = (char*)malloc(sizeof(char) * count + 1);
	res[count] = '\0';
	count--;
	while (count >= 0)
	{
		res[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (res);
}
