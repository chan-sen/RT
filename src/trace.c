
#include "./../includes/rt.h"


int		find_sphr(t_env *env, t_ray *ray, int s)
{

}

int			lower_dis(int i, int low, t_objdis **o_ds)
{
	if (low == -1 && o_ds[i])
		return (1);
	if (o_ds[i]->dis > o_ds[low]->dis)
		return (0);
	if (o_ds[i]->dis < o_ds[low]->dis)
		return (1);
}

int			find_low_dis(int objs, t_objdis **o_ds)
{
	int		i;
	int		low;

	i = 0;
	low = -1;
	while (i < objs)
	{
		if (lower_dis(i, low, o_ds))
			low = i;
		i++;
	}
	return (low);
}

t_objdis	*ray_intersects(t_env *env, t_ray *r, t_objdis **o_ds)
{
	// check ray for closest obj intersection and return that (t_objdis *)

	int		low;

	low = find_low_dis(objs_sum(env->map->nums), o_ds);



}

void check_lights(t_env *env)
{
	if (check_light(env))
		return (lit(env));
	else
		return (shade(env));
}

void traceray(t_env *env, t_ray	*ray, t_objdis **o_ds)
{
	t_objdis	*o_d:

	o_d = ray_intersects(env, ray, o_ds);
	if (o_d)
	{
		env->cam->color = ray_obj_color(env, ray, o_d);
		env->cam->ray[1] = build_light_ray(env, ray, o_d);
		env->cam->lit = check_lights(env, env->cam->ray[1]);
	}
}
