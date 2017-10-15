#include "ft_ls.h"

int			ft_time(t_time a, t_time b)
{
	if (a.month > b.month)
		return (1);
	if (a.month == b.month)
	{
		if (a.day > b.day)
			return (1);
		if (a.day == b.day)
		{
			if (a.hour > b.hour)
				return (1);
			if (a.hour == b.hour)
			{
				if (a.minute > b.minute)
					return (1);
				if (a.minute == b.minute)
					if (a.sec > b.sec)
						return (1);
			}
		}
	}
	return (0);
}

int			find_month(char *str, int i)
{
	if (i++ && !ft_strcmp(str, "Jan"))
		return (i);
	if (i++ && !ft_strcmp(str, "Feb"))
		return (i);
	if (i++ && !ft_strcmp(str, "Mar"))
		return (i);
	if (i++ && !ft_strcmp(str, "Apr"))
		return (i);
	if (i++ && !ft_strcmp(str, "May"))
		return (i);
	if (i++ && !ft_strcmp(str, "Jun"))
		return (i);
	if (i++ && !ft_strcmp(str, "Jul"))
		return (i);
	if (i++ && !ft_strcmp(str, "Aug"))
		return (i);
	if (i++ && !ft_strcmp(str, "Sep"))
		return (i);
	if (i++ && !ft_strcmp(str, "Oct"))
		return (i);
	if (i++ && !ft_strcmp(str, "Nov"))
		return (i);
	if (i++ && !ft_strcmp(str, "Dec"))
		return (i);
	return (i);
}

void		ft_find_time(t_time *tmp, struct stat buff)
{
	char 	*time;
	char 	**a;
	char 	**b;

	time = ctime(&buff.st_mtimespec.tv_sec);
	a = ft_strsplit(time, ' ');
	tmp->str_month = ft_strdup(a[1]);
	tmp->month = find_month(a[1], 0);
	tmp->day = ft_atoi(a[2]);
	b = ft_strsplit(a[3], ':');
	time = a[1];
	tmp->hour = ft_atoi(b[0]);
	tmp->minute = ft_atoi(b[1]);
	tmp->sec = ft_atoi(b[2]);
}

int 		main(int ac, char **av)
{
	t_ls	ls;

	ac = 0;
	av++;
	find_keys(&ls, &av);
	find_path(&ls, av);
	ft_ls(ls.path, ls.keys, 0);
}
