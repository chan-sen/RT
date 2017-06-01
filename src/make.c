
#include "./../includes/rt.h"

t_point	hori_plane(int x, int y, int z)
{
	t_point		ret;

	z = 1;
	ret.z = 0;
	if (x == 1 && y == 0)
	{
		ret.x = 1;
		ret.y = 0.66;
	}
	if (x == -1 && y == 0)
	{
		ret.x = -1;
		ret.y = -0.66;
	}
	if (x == 0 && y == 1)
	{
		ret.x = -0.66;
		ret.y = 1;
	}
	if (x == 0 && y == -1)
	{
		ret.x = 0.66;
		ret.y = -1;
	}
	return (ret);
}

t_point	vert_plane(int x, int y)
{
	t_point		ret;

	ret.z = 0.66;
	ret.x = x;
	ret.y = y;
	return (ret);
}

t_cam	*make_cam(void)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->camx = 0;
	cam->camy = 0;
	cam->mvspd = 5.0;
	cam->rtspd = 3.0;
	cam->pos = point_itod(0, 0, 0);
	cam->dir = point_itod(0, 0, 0);
	cam->horpl = hori_plane(1, 0, 1);
	cam->vrtpl = vert_plane(1, 0);
	cam->o_ds = NULL;
	cam->r = NULL;
	cam->obcolor = icolorto(0);
	cam->pcolor = icolorto(0);
	cam->l = 0;
	cam->t = 0;
	return (cam);
}

t_env	*make_env(void)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = NULL;
	env->win = NULL;
	env->time = 0;
	env->oldtime = 0;
	env->frametime = 0;
	env->map = make_map();
	env->cam = make_cam();
	env->image = NULL;
	env->keys = make_keys();
	return (env);
}
