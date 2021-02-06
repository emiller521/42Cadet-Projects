#ifndef FT_LS_H
# define FT_LS_H
# include "../Libft/Libft/libft.h"
# include "../b_printf/b_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <stdio.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/syslimits.h>
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct	s_args
{
	char			*dir;
	unsigned int	l : TRUE;
	unsigned int	lr : TRUE;
	unsigned int	r : TRUE;
	unsigned int	a : TRUE;
	unsigned int	t : TRUE;
	unsigned int	lt : TRUE;
	unsigned int	f : TRUE;
	t_list			*dirs;
	t_list			*dirs_pre;
	int				count;
}				t_args;

typedef struct	s_path
{
	struct stat stats;
	char		*filename;
}				t_path;

void			ft_lstsort(t_list *start, char order,
				int (*f)(t_path *, t_path *, char));
int				name_cmp(t_path *path, t_path *next, char order);
int				time_cmp(t_path *path, t_path *next, char order);
void			process_args(int ac, char **av, t_args *args);
int				dir_cmp(t_path *path, t_path *next, char order);
void			gen_info(t_path *dest, char *dir, char *filename);
int				year_length(time_t t);
void			clear_args(t_args *args);
blkcnt_t		add_blocks(t_list *list);
void			print_permissions(t_path *file);
void			print_link(t_path *file, t_args args);
void			do_ls(t_args args);
void			print_file(t_args args, t_path *file, int widths[5]);

#endif
