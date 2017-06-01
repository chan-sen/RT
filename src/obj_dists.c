
#include "./../includes/rt.h"

t_objdis		*obj_dis(const char *str, double dis, int i)
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
	return (0);
}

int		dist_order_check(t_objdis **o_ds, t_mapnums *nums)
{
	int		i;

	i = 0;
	while (i < (nums->pls + nums->sps + nums->cns + nums->cls + nums->lts))
	{
		if (o_ds[i]->dis > o_ds[i + 1]->dis)
			return (0);
		i++;
	}
	return (1);
}

void reorder_dists(t_objdis **o_ds, t_mapnums *nums)
{
	t_objdis	*swap;
	int			i;

	printf("HI\n");
	while (!dist_order_check(o_ds, nums))
	{
		if (!(o_ds[i]))
			i = 0;
		if (o_ds[i]->dis > o_ds[i + 1]->dis)
		{
			swap = o_ds[i];
			o_ds[i] = o_ds[i + 1];
			o_ds[i + 1] = swap;
		}
		i++;
	}
}

t_objdis		**find_objs(t_env *env, t_rayi *ri)
{
	t_objdis	**o_ds;
	int			i;

	o_ds = (t_objdis **)malloc(sizeof(t_objdis *) * objs_sum(env->map->nums));
	i = 0;
	while (ri_lessthan_objs(ri, env->map->nums))
	{
		printf("Hi: %f\n", env->map->objs->sphrs[ri->s]->pos.x);
		printf("he: %f\n", env->cam->pos.x);
		if (ri->p < env->map->nums->pls)
			o_ds[i++] = obj_dis("plane", distform3d(env->cam->pos,
				env->map->objs->plns[ri->p]->pos), ri->p++);
		if (ri->s < env->map->nums->sps)
			o_ds[i++] = obj_dis("sphere", distform3d(env->cam->pos,
				env->map->objs->sphrs[ri->s]->pos), ri->s++);
		if (ri->cn < env->map->nums->cns)
			o_ds[i++] = obj_dis("cone", distform3d(env->cam->pos,
				env->map->objs->cones[ri->cn]->pos), ri->cn++);
		if (ri->cl < env->map->nums->cls)
			o_ds[i++] = obj_dis("col", distform3d(env->cam->pos,
				env->map->objs->cols[ri->cl]->pos), ri->cl++);
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
