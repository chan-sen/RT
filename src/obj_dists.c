
#include "./../includes/rt.h"

t_objdis		*obj_dis(char *str, double dis, int i)
{
	t_objdis	*o_d;

	o_d = (t_objdis *)malloc(sizeof(t_objdis));
	o_d->obj = ft_strdup(str);
	o_d->obji = i;
	o_d->dis = dis;
	return (o_d);
}

t_objdis		**find_objs(t_env *env, t_rayi *ri)
{
	t_objdis	**o_ds;
	int			i;

	o_ds = (t_objdis **)malloc(sizeof(t_objdis *) * objs_sum(env->map->nums));
	i = 0;
	while (ri_lessthan_objs(ri, env->map->nums))
	{
		if (env->map->objs->plns[ri->p])
			o_ds[i++] = obj_dis("plane", distform3d(env->cam->pos,
				env->map->objs->plns[ri->p]->pos), ri->p++);
		else if (env->map->objs->sphrs[ri->s])
			o_ds[i++] = obj_dis("sphere", distform3d(env->cam->pos,
				env->map->objs->sphrs[ri->s]->pos), ri->s++);
		else if (env->map->objs->cones[ri->cn])
			o_ds[i++] = obj_dis("cone", distform3d(env->cam->pos,
				env->map->objs->cones[ri->cn]->pos), ri->cn++);
		else if (env->map->objs->cols[ri->cl])
			o_ds[i++] = obj_dis("col", distform3d(env->cam->pos,
				env->map->objs->cols[ri->cl]->pos), ri->cl++);
		else if (env->map->objs->lites[ri->lt])
			o_ds[i++] = obj_dis("lite", distform3d(env->cam->pos,
				env->map->objs->lites[ri->lt]->pos), ri->lt++);
	}
	return (o_ds);
}

t_objdis	**obj_dists(t_env *env)
{
	t_rayi		*ri;
	t_objdis	**o_ds;

	ri = set_rayi();
	o_ds = find_objs(env, ri);
	free(ri);
	return (o_ds);
}
