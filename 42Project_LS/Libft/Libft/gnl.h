/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:19:45 by elmiller          #+#    #+#             */
/*   Updated: 2019/04/02 21:24:08 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "sys/uio.h"
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 10
# define FD_LIMIT 4864

int		get_next_line(int const fd, char **line);

#endif
