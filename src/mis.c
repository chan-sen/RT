
#include "./../includes/rt.h"

void	set3to0(int *a, int *b, int *c)
{
	(*a) = 0;
	(*b) = 0;
	(*c) = 0;
}

void	set4to0(int *a, int *b, int *c, int *d)
{
	(*a) = 0;
	(*b) = 0;
	(*c) = 0;
	(*d) = 0;
}

int		usage(int err)
{
	if (err == 1)
		ft_putstr("usage: ./RT <filepath>\n");
	if (err == 2)
		ft_putstr("error: filepath invalid\n");
	return (0);
}

int		check(int argc, char **argv)
{
	char	***map;
	int		fd;

	if (argc != 2)
		return (usage(1));
	fd = open(argc[1], O_RDONLY);
	if (fd == 0)
		return (NULL);
	return (fd);
}
