#include "../includes/ft_ls.h"

char	*time_string(time_t t, t_args args)
{
	char *str;
	char *end;
	char **buff;
	char **buff2;

	end = NULL;
	str = NULL;
	buff = ft_strsplit(ft_strtrim(ctime(&t)), ' ');
	buff2 = ft_strsplit(buff[3], ':');
	if (year_length(t) == 4)
		b_printf(end, "%s", buff[4]);
	else
		b_printf(end, "%s:%s", buff2[0], buff2[1]);
	b_printf(str, "%s %2s %*s", buff[1], buff[2], 5, end);
	if (args.lt)
		b_printf(str, "%s %2s %s %s", buff[1], buff[2], buff[3], buff[4]);
	free(buff);
	free(buff2);
	return (str);
}

void	print_file(t_args args, t_path *file, int widths[5])
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;

	if (args.l)
	{
		stats = file->stats;
		pwd = getpwuid(stats.st_uid);
		grp = getgrgid(stats.st_gid);
		print_permissions(file);
		b_printf(" %*d %-*s %-*s ", widths[0], stats.st_nlink,
			widths[1], pwd->pw_name, widths[2], grp->gr_name);
		b_printf(" %*lld %s ", widths[3], stats.st_size,
			time_string(stats.st_mtime, args));
	}
	if (S_ISLNK(stats.st_mode) && args.l)
		print_link(file, args);
	else
		b_printf("%s\n", file->filename);
}

void	print_type(int mode)
{
	char		c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '-';
	b_printf("%c", c);
}

void	print_permissions(t_path *file)
{
	int			mode;

	mode = file->stats.st_mode;
	print_type(mode);
	b_printf((mode & S_IRUSR) ? "r" : "-");
	b_printf((mode & S_IWUSR) ? "w" : "-");
	if (mode & S_ISUID)
		b_printf((mode & S_IXUSR) ? "s" : "S");
	else
		b_printf((mode & S_IXUSR) ? "x" : "-");
	b_printf((mode & S_IRGRP) ? "r" : "-");
	b_printf((mode & S_IWGRP) ? "w" : "-");
	if (mode & S_ISGID)
		b_printf((mode & S_IXGRP) ? "s" : "S");
	else
		b_printf((mode & S_IXGRP) ? "x" : "-");
	b_printf((mode & S_IROTH) ? "r" : "-");
	b_printf((mode & S_IWOTH) ? "w" : "-");
	if (mode & S_ISVTX)
		b_printf((mode & S_IXUSR) ? "t" : "T");
	else
		b_printf((mode & S_IXOTH) ? "x" : "-");
}

void	print_link(t_path *file, t_args args)
{
	char *tmp;
	char *sympath;

	if (ft_strequ(args.dir, file->filename))
		tmp = file->filename;
	else
		tmp = ft_strjoin(args.dir, file->filename);
	sympath = ft_strnew(PATH_MAX);
	readlink(tmp, sympath, PATH_MAX - 1);
	b_printf("%s -> %s\n", file->filename, sympath);
	free(sympath);
}
