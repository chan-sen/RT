
#include "./../includes/rt.h"

t_cam	*make_cam(void)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->camx = 0;
	cam->camy = 0;
	cam->mvspd = 5.0;
	cam->rtspd = 3.0;
	cam->pos = point_itod(0, 0, -1000);
	cam->dir = point_itod(0, 0, 1);
	cam->o_ds = NULL;
	cam->r = (t_ray **)malloc(sizeof(t_ray *) * (3));
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
	matrix_identity(env->matrix);
	env->map = make_map();
	env->cam = make_cam();
	env->image = NULL;
	env->keys = make_keys();
	return (env);
}
