
#include "./includes/rt.h"

void set_cam(char *str, t_objects *objects, t_point p)
{
	int		i;

	i = 4;
	objects->cpx = (int)p.x;
	objects->cpy = (int)p.y;
	objects->cpz = (int)p.z;
	objects->cdx = ft_getnbr(str, &i);
	i++;
	objects->cdy = ft_getnbr(str, &i);
	i++;
	objects->cdz = ft_getnbr(str, &i);
}

void		set_sphr(char *str, t_sphr *sphr, t_point p)
{
	int		i;

	i = 7;
	sphr->xog = (int)(p.x);
	sphr->yog = (int)(p.y);
	sphr->zog = (int)(p.z);
	sphr->pos = point(p.x, p.y, p.z);
	sphr->r = ft_getnbr(str, &i);
	i++;
	sphr->color = ft_getnbr(str, &i);
}

void		set_cone(char *str, t_cone *cone, t_point p)
{
	int		i;

	i = 5;
	cone->xog = (int)(p.x);
	cone->yog = (int)(p.y);
	cone->zog = (int)(p.z);
	cone->pos = point(p.x, p.y, p.z);
	cone->r = ft_getnbr(str, &i);
	i++;
	cone->h = ft_getnbr(str, &i);
	i++;
	cone->color = ft_getnbr(str, &i);
}

void		set_col(char *str, t_col *col, t_point p)
{
	int		i;

	i = 4;
	col->xog = (int)(p.x);
	col->yog = (int)(p.y);
	col->zog = (int)(p.z);
	col->pos = point(p.x, p.y, p.z);
	col->r = ft_getnbr(str, &i);
	i++;
	col->h = ft_getnbr(str, &i);
	i++;
	col->color = ft_getnbr(str, &i);
}

void		set_lite(char *str, t_lite *lite, t_point p)
{
	lite->xog = (int)(p.x);
	lite->yog = (int)(p.y);
	lite->zog = (int)(p.z);
	lite->pos = point(p.x, p.y, p.z);
}
