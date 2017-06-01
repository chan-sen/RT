
#include "./../includes/rt.h"

t_mapnums	*set_nums(void)
{
	t_mapnums	*nums;

	nums = (t_mapnums *)malloc(sizeof(t_mapnums));
	nums->pls = 2;
	nums->lts = 2;
	nums->sps = 2;
	nums->cns = 1;
	nums->cls = 1;
	return (nums);
}

t_map	*make_map()
{
	t_map		*m;

	m = (t_map *)malloc(sizeof(t_map));
	m->nums = set_nums();
	m->objs = make_objects();
	return (m);
}
