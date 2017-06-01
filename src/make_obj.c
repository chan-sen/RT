
#include "./../includes/rt.h"

t_pln		**make_plns(int p)
{
	t_pln	**ret;

	if (p > 0){
	ret = (t_pln **)malloc(sizeof(t_pln *) * (p + 1));
	ret[p] = NULL;
	ret[0] = (t_pln *)malloc(sizeof(t_pln));
	ret[0]->xog = 25;
	ret[0]->yog = 25;
	ret[0]->zog = 0;
	ret[0]->pos = point_itod(25, 25, 0);
	ret[1] = (t_pln *)malloc(sizeof(t_pln));
	ret[1]->xog = 50;
	ret[1]->yog = 25;
	ret[1]->zog = 0;
	ret[1]->pos = point_itod(50, 25, 0);

	}
	else
		return (NULL);
	return (ret);
}

t_sphr		**make_sphrs(int s)
{
	t_sphr	**ret;

	ret = (t_sphr **)malloc(sizeof(t_sphr *) * (s + 1));
	ret[s] = NULL;
	ret[0] = (t_sphr *)malloc(sizeof(t_sphr));
	ret[0]->xog = 100;
	ret[0]->yog = 50;
	ret[0]->zog = 0;
	ret[0]->pos = point_itod(100, 50, 0);
	ret[0]->r = 10;
	ret[0]->color = icolorto(6000);
	ret[1] = (t_sphr *)malloc(sizeof(t_sphr));
	ret[1]->xog = 50;
	ret[1]->yog = 50;
	ret[1]->zog = 0;
	ret[1]->pos = point_itod(50, 50, 0);
	ret[1]->r = 5;
	ret[1]->color = icolorto(255);
	return (ret);
}

t_cone		**make_cones(int c)
{
	t_cone	**ret;

	if (c > 0)
	{
		ret = (t_cone **)malloc(sizeof(t_cone *) * (c + 1));
		ret[0] = (t_cone *)malloc(sizeof(t_cone));
		ret[0]->xog = 25;
		ret[0]->yog = 100;
		ret[0]->zog = 25;
		ret[0]->pos = point_itod(25, 100, 25);
		ret[0]->r = 0;
		ret[0]->h = 0;
		ret[0]->color = icolorto(25);
	}
	else
		return (NULL);
	return (ret);
}

t_col		**make_cols(int c)
{
	t_col	**ret;
	int		i;

	ret = (t_col **)malloc(sizeof(t_col *) * (c + 1));
	ret[c] = NULL;
	i = 0;
	if (c > 0)
	{
		ret[0] = (t_col *)malloc(sizeof(t_col));
		ret[0]->xog = 50;
		ret[0]->yog = 200;
		ret[0]->zog = 75;
		ret[0]->pos = point_itod(50, 200, 75);
		ret[0]->r = 0;
		ret[0]->h = 0;
		ret[0]->color = icolorto(0);
	}
	else
		return (NULL);
	return (ret);
}

t_lite		**make_lites(int l)
{
	t_lite	**ret;

	ret = (t_lite **)malloc(sizeof(t_lite *) * (l + 1));
	ret[l] = NULL;
	if (l > 0)
	{
		ret[0] = (t_lite *)malloc(sizeof(t_lite));
		ret[0]->xog = 25;
		ret[0]->yog = 50;
		ret[0]->zog = 50;
		ret[0]->pos = point_itod(0, 50, -2000);
		ret[0]->lit = icolorto(16581374);
		ret[1] = (t_lite *)malloc(sizeof(t_lite));
		ret[1]->xog = 50;
		ret[1]->yog = 50;
		ret[1]->zog = 50;
		ret[1]->pos = point_itod(50, 500, -1500);
		ret[1]->lit = icolorto(16581374);
	}
	else
		return (NULL);
	return (ret);
}

t_objects	*make_objects()
{
	t_objects	*ret;

	ret = (t_objects *)malloc(sizeof(t_objects));
	ret->pln = 0;
	ret->s = 0;
	ret->con = 0;
	ret->col = 0;
	ret->lte = 0;
	ret->plns = make_plns(2);
	ret->sphrs = make_sphrs(2);
	ret->cones = make_cones(1);
	ret->cols = make_cols(1);
	ret->lites = make_lites(2);
	return (ret);
}
