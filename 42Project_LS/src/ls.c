#include "../includes/ft_ls.h"

void	set_widths(int widths[5], t_list *files)
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;
	int				num_len;

	widths[0] = 0;
	widths[1] = 0;
	widths[2] = 0;
	widths[3] = 0;
	widths[4] = 0;
	while (files)
	{
		stats = ((t_path *)files->content)->stats;
		pwd = getpwuid(stats.st_uid);
		grp = getgrgid(stats.st_gid);
		num_len = b_printf("%hu", stats.st_nlink);
		widths[0] = MAX(num_len, widths[0]);
		widths[1] = MAX((int)ft_strlen(pwd->pw_name) + 1, widths[1]);
		widths[2] = MAX((int)ft_strlen(grp->gr_name), widths[2]);
		num_len = b_printf("%d", stats.st_size);
		widths[3] = MAX(num_len, widths[3]);
		widths[4] = MAX(year_length(stats.st_mtime), widths[4]);
		files = files->next;
	}
	widths[0]++;
}

void	iterate_files(t_list *files, t_args *args, char *current_dir)
{
	t_list			*iter;
	int				widths[5];
	t_path			*cont;

	set_widths(widths, files);
	iter = files;
	while (iter)
	{
		print_file(*args, iter->content, widths);
		iter = iter->next;
	}
	iter = files;
	while (args->lr && iter)
	{
		cont = ((t_path *)iter->content);
		if (S_ISDIR(cont->stats.st_mode) && !(ft_strequ(cont->filename, ".")
			|| ft_strequ(((t_path *)iter->content)->filename, "..")))
		{
			ft_putchar('\n');
			b_printf("%s%s:\n", current_dir, cont->filename);
			args->dir = ft_strjoin(current_dir, cont->filename);
			do_ls(*args);
		}
		iter = iter->next;
	}
}

int		handle_error(t_args *args, t_path *path, t_list **files)
{
	if (errno == 13)
	{
		b_printf("ls: %s\n", args->dir);
		b_printf("ls: %s\n", strerror(errno));
		return (1);
	}
	args->dir[ft_strlen(args->dir) - 1] = 0;
	errno = 0;
	gen_info(path, "", args->dir);
	if (errno)
	{
		b_printf("ls: %s\n", args->dir);
		b_printf("ls: %s\n", strerror(errno));
		return (1);
	}
	ft_lst_add_back(files, ft_lstnew(path, sizeof(t_path)));
	return (0);
}

void	read_dir(DIR *d, t_args args, t_list **files, t_path *path)
{
	struct dirent	*dir;

	while ((dir = readdir(d)) > 0)
	{
		if (!args.a && dir->d_name[0] == '.')
			continue;
		gen_info(path, args.dir, dir->d_name);
		ft_lst_add_back(files, ft_lstnew(path, sizeof(t_path)));
	}
	ft_lstsort(*files, args.r, args.t ? time_cmp : name_cmp);
	closedir(d);
}

void	do_ls(t_args args)
{
	DIR				*d;
	t_list			*files;
	t_path			path;
	char			*current_dir;

	files = 0;
	args.dir = ft_strjoin(args.dir ? args.dir : ".", "/");
	current_dir = ft_strdup(args.dir);
	errno = 0;
	d = opendir(args.dir);
	if (errno)
	{
		if (handle_error(&args, &path, &files))
			return ;
	}
	else
	{
		read_dir(d, args, &files, &path);
		if (args.l && files)
			b_printf("total %lld\n", add_blocks(files));
		printf("hereee\n");
	}
	iterate_files(files, &args, current_dir);
}
