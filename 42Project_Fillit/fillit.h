/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 10:58:57 by elmiller          #+#    #+#             */
/*   Updated: 2019/05/04 10:59:11 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# define MAX_TETRA 26
# define MAX_GRID 4

typedef struct	s_tetra
{
	char		name;
	int			x[MAX_GRID];
	int			y[MAX_GRID];
}				t_tetra;

void			error(void);
int				size_of_file(char *arg);
int				find_num_tetra(char *str);
void			print_map(char **map);
char			**get_next_tetra(const int fd);
int				check_char(char **tetra);
int				add_count(char **tetra, int i, int j);
int				check_hash(char **tetra);
int				check_newline(char *line);
t_tetra			get_coords(char **grid);
t_tetra			reset_coords(t_tetra tetra);
char			**initial_map(int num);
char			**make_map(int num);
char			**place_tetra(t_tetra tetra, char **map, int y, int x);
char			**remove_tetra(char **map, char name, int size);
int				placement_check(t_tetra tetra, char **map, int y, int x);
int				can_place(t_tetra tetra, char **map, int y, int x);
char			**resize_map(char **map);
int				backtrack(t_tetra list[MAX_TETRA], char **map, int i, int size);
char			**fillit(char **map, t_tetra list[MAX_TETRA], int size);
void			finish(t_tetra list[MAX_TETRA], int num);

#endif
