
#include "./../includes/rt.h"


int			lower_dis(int i, int low, t_objdis **o_ds)
{
	if (low == -1 && o_ds[i])
		return (1);
	if (o_ds[i]->dis > o_ds[low]->dis)
		return (0);
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

int	sphere_closest_intersect(double b, double disc, double *t)
{
	double		sqrtdisc;
	double		t0;
	double		t1;

	sqrtdisc = sqrt(disc);
	t0 = ((-b) + sqrtdisc) / 2;
	t1 = ((-b) - sqrtdisc) / 2;
	if (t0 > t1)
		t0 = t1;
	if ((t0 > 0.001) && (t0 < *t))
	{
		*t = t0;
		return (1);
	}
	else
		return (0);
}

int	sphere_intersect_check(t_sphr *s, t_ray *ray, double *t)
{
	double		a;
	double		b;
	double		c;
	t_point		d;
	double		disc;

	a = dot_product(ray->rd, ray->rd);
	d = sub_vectors(ray->rp, s->pos);
	b = 2 * dot_product(ray->rd, d);
	c = dot_product(d, d) - (s->r * s->r);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	else
		return (sphere_closest_intersect(b, disc, t));
}

int obj_intersect_check(t_env *env, t_ray *ray, t_objdis *od)
{
	if (0 == ft_strcmp(od->obj, "sphere"))
		return (sphere_intersect_check(env->map->objs->sphrs[od->obji],
			ray, &env->cam->t));
	// else if (0 == ft_strcmp(od->obj, "plane"))
	// 	plane_intersect_check() ? 1 : 0;
	// else if (0 == ft_strcmp(od->obj, "cone"))
	// 	cone_intersect_check() ? 1 : 0;
	// else if (0 == ft_strcmp(od->obj, "col"))
	// 	col_intersect_check() ? 1 : 0;
	// else if (0 == ft_strcmp(od->obj, "lite"))
	// 	lite_intersect_check() ? 1 : 0;
	return (0);
}

t_objdis	*ray_intersects(t_env *env, t_ray *r, t_objdis **o_ds)
{
	int		i;

	i = 0;
	while (o_ds[i])
	{
		if (obj_intersect_check(env, r, o_ds[i]))
			return (o_ds[i]);
		i++;
	}
	return (NULL);
}

t_vmath		*sphere_intersect_spot(t_env *env, t_ray *r, t_objdis *o_d)
{
	t_vmath	*v;

	v = (t_vmath *)malloc(sizeof(t_vmath));
	v->news = add_vectors(r->rp, scale_vectors(env->cam->t, r->rd));
	v->n = sub_vectors(v->news, env->map->objs->sphrs[o_d->obji]->pos);
	v->tmp = dot_product(v->n, v->n);
	if (v->tmp == 0)
		return (NULL);
	v->tmp = 1.0 / sqrt(v->tmp);
	v->n = scale_vectors(v->tmp, v->n);
	return (v);
}

t_vmath		*intersection_spot(t_env *env, t_ray *r, t_objdis *od)
{
	t_vmath	*ret;

	ret = NULL;
	if (0 == ft_strcmp(od->obj, "sphere"))
		ret = sphere_intersect_spot(env, r, od);
	// else if (0 == ft_strcmp(od->obj, "plane"))
	// 	ret = plane_intersect_spot();
	// else if (0 == ft_strcmp(od->obj, "cone"))
	// 	ret = cone_intersect_spot();
	// else if (0 == ft_strcmp(od->obj, "col"))
	// 	ret = col_intersect_spot();
	// else if (0 == ft_strcmp(od->obj, "lite"))
	// 	ret = lite_intersect_spot();
	return (ret);
}

t_color		ray_obj_color(t_env *env, t_objdis *od)
{
	t_color	ret;

	ret = icolorto(0);
	if (0 == ft_strcmp(od->obj, "sphere"))
		ret = env->map->objs->sphrs[od->obji]->color;
	// else if (0 == ft_strcmp(od->obj, "plane"))
	// 	ret = env->map->objs->plns[od->obji]->color;
	// else if (0 == ft_strcmp(od->obj, "cone"))
	// 	ret = env->map->objs->cones[od->obji]->color;
	// else if (0 == ft_strcmp(od->obj, "col"))
	// 	ret = env->map->objs->cols[od->obji]->color;
	// else if (0 == ft_strcmp(od->obj, "lite"))
	// 	ret = env->map->objs->lites[od->obji]->color;
	return (ret);
}

t_ray	*build_light_ray(t_env *env, t_vmath *v)
{
	t_ray	*r;
	t_point	dist;
	double	t;

	r = NULL;
	dist = sub_vectors(env->map->objs->lites[env->cam->l - 1]->pos, v->news);
	if (dot_product(v->n, dist) <= 0.0)
		return (NULL);
	t = sqrt(dot_product(dist, dist));
	if (t <= 0.0)
		return (NULL);
	r = (t_ray *)malloc(sizeof(t_ray));
	r->rp = v->news;
	r->rd = scale_vectors((1 / t), dist);
	return (r);
}

t_color	add_colors(t_color pcolor, t_color lamb)
{
	t_color	r;

	r.r = pcolor.r + lamb.r;
	r.g = pcolor.g + lamb.g;
	r.b = pcolor.b + lamb.b;
	return (r);
}

t_color	diffuse_lamb(t_lite *l, t_ray *r, t_point n, t_color c)
{
	t_color	lamb;
	double	lambert;

	lambert = dot_product(r->rd, n);
	lamb.r = lambert * l->lit.r * c.r;
	lamb.g = lambert * l->lit.g * c.g;
	lamb.b = lambert * l->lit.b * c.b;
	return (lamb);
}


void	traceray(t_env *env, t_ray	*r, t_objdis **o_ds)
{
	t_objdis	*o_d;
	t_vmath		*v;

	reorder_dists(o_ds, env->map->nums);
	env->cam->t = 20000.0;
	o_d = ray_intersects(env, r, o_ds);
	if (o_d)
	{
		v = intersection_spot(env, r, o_d);
		if (v)
		{
			env->cam->l = 1;
			env->cam->obcolor = ray_obj_color(env, o_d);
			while (env->cam->l <= env->map->nums->lts)
			{
				env->cam->r[env->cam->l] = build_light_ray(env, v);
				if (env->cam->r[env->cam->l])
					env->cam->pcolor = add_colors(env->cam->pcolor,
						diffuse_lamb(env->map->objs->lites[env->cam->l],
							env->cam->r[env->cam->l], v->n, env->cam->obcolor));
				env->cam->l++;
			}
		}
	}
	if (!o_d)
		env->cam->pcolor = icolorto(0);
}
