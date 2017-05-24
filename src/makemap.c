
#include "./includes/rt.h"

void pull_xyz(char *str, int *x, int *y, int *z)
{
	int		i;

	i = 0;
	(*x) = ft_getnbr(str, &i);
	(*y) = ft_getnbr(str, &i);
	(*z) = ft_getnbr(str, &i);
}

int		*fill_row(int fd, int mx, t_objects *objects);
{
	int		*ret;
	char	*line;
	int		x;
	int		i;

	line = NULL;
	if (0 == get_next_line(fd, &line))
		return (NULL);
	ret = (int *)malloc(sizeof(int) * mx);
	x = 0;
	i = 0;
	while (x < mx)
	{
		if (ft_isdigit(line[i]))
			ret[y][x] = get_nbr(line, &i);
		else
		{
			ret[y][x] = 0;
			fill_object(get_word(line, &i), objects);
		}
		if (line[i] == ' ')
			i++;
		i++;
		x++;
	}
	y++;
}

int		**fill_layer(int fd, int mx, int my, t_objects *objects)
{
	int		**ret;
	int		x;
	int		y;

	y = 0;
	ret = (int **)malloc(sizeof(int *) * my)
	while (y < my)
		ret[y++] = fill_row(fd, mx, objects);
	return (ret);
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
	fd = check(argc, argv);
	map = (t_map *)malloc(sizeof(t_map));
	if (1 == get_next_line(fd, &line))
		pull_xyz(line, &map->x, &map->y, &map->z);
	if (1 == get_next_line(fd, &line))
		pull_lites(line, &map->lts);
	if (1 == get_next_line(fd, &line))
		pull_objs(line, &map->sps, &map->cns, &map->cls);
	map->objects = make_objects(map->lts, map->sps, map->cns, map->cls);
	map->map = (int ***)malloc(sizeof(int **) * map->z);
	while (z < map->z)
		map->map[z++] = fill_layer(fd, map->x, map->y, map->objects);
	return (map);
}
