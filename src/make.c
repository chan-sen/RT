
#include "./../includes/rt.h"

t_point	hori_plane(t_point *dir)
{
	t_point		ret;

	dir->z == 1;
	ret.z = 0;
	if (dir->x == 1 && dir->y == 0)
	{
		ret.x = 1;
		ret.y = 0.66;
	}
	if (dir->x == -1 && dir->y == 0)
	{
		ret.x = -1;
		ret.y = -0.66;
	}
	if (dir->x == 0 && dir->y == 1)
	{
		ret.x = -0.66;
		ret.y = 1;
	}
	if (dir->x == 0 && dir->y == -1)
	{
		ret.x = 0.66;
		ret.y = -1;
	}
	return (ret);
}

t_point	vert_plane(t_point *dir)
{
	t_point		ret;

	ret.z = 0.66;
	ret.x = dir->x;
	ret.y = dir->y;
	return (ret);
}

t_cam	*make_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->camx = 0;
	cam->camy = 0;
	cam->rfract = 0;
	cam->rflect = 0;
	cam->mvspd = 5.0;
	cam->rtspd = 3.0;
	cam->pos = point_itod(map->objs->cpx, map->objs->cpy, map->objs->cpz);
	cam->dir = point_itod(map->objs->cdx, map->objs->cdy, map->objs->cdz);
	cam->horpl = hori_plane(&cam->dir);
	cam->vrtpl = vert_plane(&cam->dir);
	cam->r = NULL;
	return (cam);
}

t_env	*make_env(int argc, char **argv)
{
	t_env		*env;
	int			fd;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = NULL;
	env->win = NULL;
	env->time = 0;
	env->oldtime = 0;
	env->frametime = 0;
	env->map = make_map();
	env->cam = make_cam(env->map);
	env->img = NULL;
	env->keys = make_keys();
	return (env);
}

t_img		make_img(void *mlx)
{
	t_img	image;

	image.img = mlx_new_image(mlx, WIN_WDT, WIN_HGT);
	image.data = mlx_get_data_addr(image.img, &image.bits,
		&image.sizeline, &image.endian);
	image.height = WIN_HGT;
	image.width = WIN_WDT;
	return (image);
}
