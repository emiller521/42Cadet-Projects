#include "../includes/ft_ls.h"

void	iterate_dirs(t_args args, t_path *path)
{
	struct stat	stats;
	int			sym_is_dir;
	int			x;

	x = -1;
	ft_lstsort(args.dirs, args.r, args.t ? time_cmp : name_cmp);
	ft_lstsort(args.dirs, 0, dir_cmp);
	while (args.dirs)
	{
		x++;
		path = ((t_path *)(args.dirs->content));
		args.dir = path->filename;
		sym_is_dir = 0;
		if (stat(args.dir, &stats) != -1 && S_ISDIR(stats.st_mode))
			sym_is_dir = 1;
		if (args.count > 1 && (sym_is_dir || S_ISDIR(path->stats.st_mode)))
		{
			if (x > 0)
				ft_putchar('\n');
			b_printf("%s:\n", args.dir);
		}
		do_ls(args);
		args.dirs = args.dirs->next;
	}
}

int		main(int ac, char **av)
{
	t_args		args;
	t_path		*path;

	clear_args(&args);
	args.dirs = NULL;
	process_args(ac, av, &args);
	path = (t_path *)ft_memalloc(sizeof(t_path));
	args.dir = ".";
	if (args.count == 0)
		do_ls(args);
	else
	{
		ft_lstsort(args.dirs_pre, 0, name_cmp);
		while (args.dirs_pre)
		{
			gen_info(path, "", ((t_path *)args.dirs_pre->content)->filename);
			if (path->filename)
				ft_lst_add_back(&args.dirs, ft_lstnew(path, sizeof(t_path)));
			args.dirs_pre = args.dirs_pre->next;
		}
		iterate_dirs(args, path);
	}
	return (0);
}
