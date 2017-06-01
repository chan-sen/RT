

#include "./../includes/rt.h"

t_point		cam_dir(t_env *env)
{
	t_point		cd;
	double		camx;
	double		camy;

	camx = 2 * env->cam->camx / (double)(WIN_WDT - 1);
	camy = 2 * env->cam->camy / (double)(WIN_HGT - 1);
	cd.x = env->cam->dir.x + env->cam->horpl.x + env->cam->vrtpl.x
		* (camx + camy);
	cd.y = env->cam->dir.y + env->cam->horpl.y + env->cam->vrtpl.y
		* (camx + camy);
	cd.z = env->cam->dir.z + env->cam->horpl.z + env->cam->vrtpl.z
		* (camx + camy);

	return (cd);
}

t_ray		*cam_ray(t_env *env)
{
	t_ray	*cr;

	cr = (t_ray *)malloc(sizeof(t_ray));
	cr->rp = point(env->cam->pos.x, env->cam->pos.y, env->cam->pos.z);
	cr->rd = cam_dir(env);
	return (cr);
}

void buildray(t_env *env)
{
	// if (env->cam->r)
	// 	clear_rays(env->cam->r);
	env->cam->r = (t_ray **)malloc(sizeof(t_ray *)
		* (1 + env->map->nums->lts));
	env->cam->r[0] = cam_ray(env);
}
