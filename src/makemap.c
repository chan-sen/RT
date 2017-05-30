
#include "./../includes/rt.h"

void	pull_xyz(char *str, int *x, int *y, int *z)
{
	int		i;

	i = 0;
	(*x) = ft_getnbr(str, &i);
	(*y) = ft_getnbr(str, &i);
	(*z) = ft_getnbr(str, &i);
}

void	fill_object(char *str, t_objects *objects, t_point p)
{
	if (0 == ft_strncmp(str, "cam", 3))
		set_cam(str, objects, p);
	else if (0 == ft_strncmp(str, "sphere", 6))
		set_sphr(str, objects->sphrs[objects->s++], p);
	else if (0 == ft_strcmp(str, "light", 5))
		set_lite(str, objects->lites[objects->lte++], p);
	else if (0 == ft_strncmp(str, "cone", 4))
		set_cone(str, objects->cones[objects->con++], p);
	else if (0 == ft_strncmp(str, "col", 3))
		set_col(str, objects->cols[objects->col++], p);
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
			ret[y][x] = ft_get_nbr(line, &i);
		else
		{
			ret[y][x] = 0;
			fill_object(get_word(line, &i), objects, point_itod(x, y, z));
		}
		if (line[i] == ' ')
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

t_mapnums	*pull_nums(int fd)
{
	t_mapnums	*nums;
	char		*line;

	line = NULL;
	nums = (t_mapnums *)malloc(sizeof(t_mapnums));
	set3to0(&nums->x, &nums->y, &nums->z);
	set4to0(&nums->lts, &nums->sps, &nums->cns, &nums->cls);
	if (1 == get_next_line(fd, &line))
		pull_xyz(line, &nums->x, &nums->y, &nums->z);
	if (1 == get_next_line(fd, &line))
		pull_lites(line, &nums->lts);
	if (1 == get_next_line(fd, &line))
		pull_objs(line, &nums->sps, &nums->cns, &nums->cls);
	return (nums);
}

t_map	*make_map(int argc, char *argv)
{
	t_map		*m;
	int			z;

	line = NULL;
	z = 0;
	fd = check(argc, argv);
	m = (t_map *)malloc(sizeof(t_map));
	m->nums = pull_nums(fd);
	m->objs = make_objects(m->nums);
	m->map = (int ***)malloc(sizeof(int **) * m->nums->z);
	while (z < m->nums->z)
		m->map[z++] = fill_layer(fd, m->nums->x, m->nums->y, m->objects);
	return (m);
}
