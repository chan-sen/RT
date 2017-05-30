
#include "./../includes/rt.h"


void traceray(t_env *env, t_ray	*ray)
{
	if (ray_intersects(env, ray))
	{
		if (light_ray(env))
			lit_or_shade();
	}
	ray_color(env);
}
