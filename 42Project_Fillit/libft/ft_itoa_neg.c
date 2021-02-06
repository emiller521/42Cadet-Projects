/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 04:39:41 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/06 04:39:59 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_neg(int n, int count)
{
	char *res;

	if (!(res = (char*)malloc(sizeof(char) * count + 2)))
		return (NULL);
	res = (char*)malloc(sizeof(char) * count + 2);
	res[0] = '-';
	res[count + 1] = '\0';
	n = -n;
	while (count >= 1)
	{
		res[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (res);
}
