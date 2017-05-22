
#include "./includes/rt.h"

void pull_xyz(char *str, int *x, int *y, int *z)
{
	int		i;

	i = 0;
	(*x) = ft_getnbr(str, &i);
	(*y) = ft_getnbr(str, &i);
	(*z) = ft_getnbr(str, &i);
}

int		**filllayer(int mx, int my)
{
	int		**ret;
	int		x;
	int		y;

	y = 0;
	ret = (int **)malloc(sizeof(int *) * my)
	while (y < my)
	{
		ret[y] = (int *)malloc(sizeof(int) * mx);
		x = 0;
		while (x < mx)
		{
			x++;
		}
		y++;
	}
}

t_map	*make_map(int argc, char *argv)
{
	t_map		*map;
	char		*line;
	int			z;
	int			y;
	int			x;

	line = NULL;
	set3to0(&z, &y, &x);
	map = (t_map *)malloc(sizeof(t_map));
	if (1 == get_next_line(fd, &line))
	{
		pull_xyz(line, &map->x, &map->y, &map->z);
	}
	map->map = (int ***)malloc(sizeof(int **) * map->z);
	while (z < map->z)
	{
		map->map[z++] = filllayer(map->x, map->y);
		(int **)malloc(sizeof(int *) * map->y);
		while (y < map->y)
		{
			map->
		}
	}
}
