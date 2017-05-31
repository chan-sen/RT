
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
	else if (0 == ft_strncmp(str, "light", 5))
		set_lite(str, objects->lites[objects->lte++], p);
	else if (0 == ft_strncmp(str, "cone", 4))
		set_cone(str, objects->cones[objects->con++], p);
	else if (0 == ft_strncmp(str, "col", 3))
		set_col(str, objects->cols[objects->col++], p);
}

int		*fill_row(char *line, t_mapnums *nums, t_objects *objects)
{
	int		*ret;
	int		x;
	int		i;

	line = NULL;
	ret = (int *)malloc(sizeof(int) * nums->x);
	x = nums->x;
	nums->x = 0;
	i = 0;
	while (nums->x < x)
	{
		if (ft_isdigit(line[i]))
			ret[nums->x++] = ft_getnbr(line, &i);
		else
		{
			ret[nums->x++] = 0;
			fill_object(ft_getword(line, &i), objects,
				point_itod(nums->x++, nums->y, nums->z));
		}
		if (line[i] == ' ')
			i++;
	}
	return (ret);
}

int		**fill_layer(int fd, t_mapnums *nums, t_objects *objects)
{
	int		**ret;
	char	*line;
	int		y;

	ret = (int **)malloc(sizeof(int *) * nums->y);
	y = nums->y;
	nums->y = 0;
	while (nums->y < y)
	{
		if (0 == get_next_line(fd, &line))
			return (NULL);
		ret[nums->y++] = fill_row(line, nums, objects);
	}
	return (ret);
}

void pull_lites(char *s, int *lts)
{
	int		i;

	i = 0;
	(*lts) = ft_getnbr(s, &i);
}

void pull_objs(char *s, int *sps, int *cns, int *cls)
{
	int		i;

	i = 0;
	(*sps) = ft_getnbr(s, &i);
	(*cns) = ft_getnbr(s, &i);
	(*cls) = ft_getnbr(s, &i);
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

t_map	*make_map(int argc, char **argv)
{
	t_map		*m;
	int			fd;
	int			z;

	fd = check(argc, argv);
	m = (t_map *)malloc(sizeof(t_map));
	m->nums = pull_nums(fd);
	m->objs = make_objects(m->nums);
	m->map = (int ***)malloc(sizeof(int **) * m->nums->z);
	z = m->nums->z;
	m->nums->z = 0;
	while (m->nums->z < z)
		m->map[m->nums->z++] = fill_layer(fd, m->nums, m->objs);
	return (m);
}
