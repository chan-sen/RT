
#include "./../includes/rt.h"

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
