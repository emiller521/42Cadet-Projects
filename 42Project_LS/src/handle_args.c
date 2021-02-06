#include "../includes/ft_ls.h"

void	set_arg(t_args *args, char c)
{
	if (c == 'l')
		args->l = TRUE;
	else if (c == 'R')
		args->lr = TRUE;
	else if (c == 'r')
		args->r = TRUE;
	else if (c == 'a')
		args->a = TRUE;
	else if (c == 't')
		args->t = TRUE;
	else if (c == 'f')
		args->f = TRUE;
	else if (c == '1')
		args->l = TRUE;
	else if (c == 'T')
		args->lt = TRUE;
	else
	{
		ft_putstr("ls: illegal option -- %c\n");
		ft_putstr("usage: ls [-lsartR] [file ...]\n");
		exit(1);
	}
}

void	handle_dash(char **av, int count, int *end, t_args *args)
{
	int iter;

	iter = 1;
	while (av[count][iter])
	{
		if (av[count][iter] == '-' && !av[count][iter + 1] && iter == 1)
		{
			*end = 1;
			break ;
		}
		set_arg(args, av[count][iter++]);
	}
}

void	process_args(int ac, char **av, t_args *args)
{
	int		count;
	t_path	tmp;
	int		end;

	count = 0;
	args->count = 0;
	end = 0;
	while (++count < ac)
	{
		if (av[count][0] == '-' && !end && av[count][1])
			handle_dash(av, count, &end, args);
		else
		{
			if (av[count][0] == 0)
			{
				printf("ls: fts_open: No such file or directory\n");
				exit(1);
			}
			end = (ft_strequ(av[count], "-")) ? 1 : end;
			tmp.filename = ft_strdup(av[count]);
			ft_lst_add_back(&args->dirs_pre, ft_lstnew(&tmp, sizeof(t_path)));
			args->count++;
		}
	}
}
