/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:40:08 by cdimitro          #+#    #+#             */
/*   Updated: 2019/03/01 23:48:45 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *ptr;

	if (alst == NULL)
		return ;
	ptr = *alst;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = tmp;
	}
	*alst = NULL;
}
