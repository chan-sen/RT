
#include "./../includes/rt.h"

t_point		scale_vectors(double c, t_point v)
{
	t_point	ret;

	ret = point((v.x * c), (v.y * c), (v.z * c));
	return (ret);
}

t_point		add_vectors(t_point a, t_point b)
{
	t_point	ret;

	ret = point((a.x + b.x), (a.y + b.y), (a.z + b.z));
	return (ret);
}

double		dot_product(t_point *a, t_point *b)
{
	printf("ha%p\n", a);
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_point		sub_vectors(t_point a, t_point b)
{
	t_point	ret;

	printf("x: %f y: %f z: %f\n", b.x, b.y, b.z);
	printf("a.x: %f y: %f z: %f\n", a.x, a.y, a.z);
	ret = point((a.x - b.x), (a.y - b.y), (a.z - b.z));
	printf("ret.x: %f y: %f z: %f\n", ret.x, ret.y, ret.z);
	return (ret);
}

t_point		point(double x, double y, double z)
{
	t_point		point;

	point.x = (double)(x);
	point.y = (double)(y);
	point.z = (double)(z);
	return (point);
}

t_point		point_itod(int x, int y, int z)
{
	t_point		point;

	point.x = (double)(x);
	point.y = (double)(y);
	point.z = (double)(z);
	return (point);
}
