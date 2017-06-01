
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

int		ri_lessthan_objs(t_rayi *ri, t_mapnums *nums)
{
	if (ri->p < nums->pls)
		return (1);
	if (ri->s < nums->sps)
		return (1);
	if (ri->cn < nums->cns)
		return (1);
	if (ri->cl < nums->cls)
		return (1);
	if (ri->lt < nums->lts)
		return (1);
	return (0);
}

t_objdis		**find_objs(t_env *env, t_rayi *ri)
{
	t_objdis	**o_ds;
	int			i;

	o_ds = (t_objdis **)malloc(sizeof(t_objdis *) * objs_sum(env->map->nums));
	i = 0;
	while (ri_lessthan_objs(ri, env->map->nums))
	{
		if (env->map->objs->plns)
			o_ds[i++] = obj_dis("plane", distform3d(env->cam->pos,
				env->map->objs->plns[ri->p]->pos), ri->p++);
		if (env->map->objs->sphrs)
			o_ds[i++] = obj_dis("sphere", distform3d(env->cam->pos,
				env->map->objs->sphrs[ri->s]->pos), ri->s++);
		if (env->map->objs->cones)
			o_ds[i++] = obj_dis("cone", distform3d(env->cam->pos,
				env->map->objs->cones[ri->cn]->pos), ri->cn++);
		if (env->map->objs->cols)
			o_ds[i++] = obj_dis("col", distform3d(env->cam->pos,
				env->map->objs->cols[ri->cl]->pos), ri->cl++);
		if (env->map->objs->lites)
			o_ds[i++] = obj_dis("lite", distform3d(env->cam->pos,
				env->map->objs->lites[ri->lt]->pos), ri->lt++);
		printf("%s: dis: %f\n", o_ds[i]->obj, o_ds[i]->dis);
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
