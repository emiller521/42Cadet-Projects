#include "../includes/ft_ls.h"

void		gen_info(t_path *dest, char *dir, char *filename)
{
	char	*tmp;

	tmp = ft_strjoin(dir, filename);
	errno = 0;
	if (lstat(tmp, &dest->stats) == -1)
	{
		b_printf("ls: %s:\n", tmp);
		b_printf("ls: %s:\n", strerror(errno));
		dest->filename = 0;
		free(tmp);
		return ;
	}
	free(tmp);
	dest->filename = ft_strdup(filename);
}

int			year_length(time_t t)
{
	long	diff;

	diff = time(0) - t;
	if (diff > 15552000 || diff < -15552000)
		return (4);
	else
		return (5);
}

void		clear_args(t_args *args)
{
	args->l = FALSE;
	args->lr = FALSE;
	args->r = FALSE;
	args->a = FALSE;
	args->f = FALSE;
	args->t = FALSE;
}

blkcnt_t	add_blocks(t_list *list)
{
	blkcnt_t ret;

	ret = 0;
	while (list)
	{
		ret += ((t_path *)list->content)->stats.st_blocks;
		list = list->next;
	}
	return (ret);
}
