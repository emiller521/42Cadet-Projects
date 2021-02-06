/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:28:57 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/06 19:51:55 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		store;
	int		count;
	char	*res;

	store = n;
	count = 1;
	res = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (store > 9)
	{
		store /= 10;
		count++;
	}
	while (store < -9)
	{
		store /= 10;
		count++;
	}
	if (n < 0)
		res = ft_itoa_neg(n, count);
	else
		res = ft_itoa_pos(n, count);
	return (res);
}
