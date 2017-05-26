
#include "./../includes/rt.h"

t_sphr		**make_sphrs(int s)
{
	t_sphr	**ret;
	int		i;

	ret = (t_sphr **)malloc(sizeof(t_sphr *) * (s + 1));
	ret[l] = NULL;
	i = 0;
	while (i < l)
	{
		ret[i] = (t_sphr *)malloc(sizeof(t_sphr));
		ret[i]->xog = 0;
		ret[i]->yog = 0;
		ret[i]->zog = 0;
		ret[i]->pos = point(0, 0, 0);
		ret[i]->r = 0;
		ret[i]->shine = 0;
		ret[i]->color = 0;
		i++;
	}
	return (ret);
}

t_cone		**make_cones(int c)
{
	t_cone	**ret;
	int		i;

	ret = (t_cone **)malloc(sizeof(t_cone *) * (c + 1));
	ret[l] = NULL;
	i = 0;
	while (i < l)
	{
		ret[i] = (t_cone *)malloc(sizeof(t_cone));
		ret[i]->xog = 0;
		ret[i]->yog = 0;
		ret[i]->zog = 0;
		ret[i]->pos = point(0, 0, 0);
		ret[i]->r = 0;
		ret[i]->h = 0;
		ret[i]->shine = 0;
		ret[i]->color = 0;
		i++;
	}
	return (ret);
}

t_col		**make_cols(int c)
{
	t_col	**ret;
	int		i;

	ret = (t_col **)malloc(sizeof(t_col *) * (c + 1));
	ret[l] = NULL;
	i = 0;
	while (i < l)
	{
		ret[i] = (t_col *)malloc(sizeof(t_col));
		ret[i]->xog = 0;
		ret[i]->yog = 0;
		ret[i]->zog = 0;
		ret[i]->pos = point(0, 0, 0);
		ret[i]->r = 0;
		ret[i]->h = 0;
		ret[i]->shine = 0;
		ret[i]->color = 0;
		i++;
	}
	return (ret);
}

t_lite		**make_lites(int l)
{
	t_lite	**ret;
	int		i;

	ret = (t_lite **)malloc(sizeof(t_lite *) * (l + 1));
	ret[l] = NULL;
	i = 0;
	while (i < l)
	{
		ret[i] = (t_lite *)malloc(sizeof(t_lite));
		ret[i]->xog = 0;
		ret[i]->yog = 0;
		ret[i]->zog = 0;
		ret[i]->pos = point(0, 0, 0);
		ret[i]->r = 0;
		ret[i]->shine = 0;
		i++;
	}
	return (ret);
}

t_objects	*make_objects(int lte, int s, int cns, int cls)
{
	t_objects	*ret;

	ret = (t_object *)malloc(sizeof(t_object));
	ret->cpx = 0;
	ret->cpy = 0;
	ret->cpz = 0;
	ret->cdx = 0;
	ret->cdy = 0;
	ret->cdz = 0;
	ret->(*s) = 0;
	ret->(*con) = 0;
	ret->(*col) = 0;
	ret->(*lte) = 0;
	ret->sphrs = make_sphrs(s);
	ret->cones = make_cones(cns);
	ret->cols = make_cols(cls);
	ret->lites = make_lites(lts);
	return (ret);
}
