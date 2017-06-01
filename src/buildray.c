

#include "./../includes/rt.h"

int		cam_ray(t_env *env, int x, int y)
{
	t_point	tmp;
	t_point	yah;

	env->cam->r[0] = (t_ray *)malloc(sizeof(t_ray));
	tmp =  point(x, y, 90 * 10);
	printf("x: %f y: %f z: %f\n", env->cam->pos.x, env->cam->pos.y, env->cam->pos.z);

	env->cam->r[0]->rp = point(env->cam->pos.x, env->cam->pos.y, env->cam->pos.z);

	printf("x: %f y: %f z: %f\n", env->cam->r[0]->rp.x, env->cam->r[0]->rp.y, env->cam->r[0]->rp.z);

	vct_mult_mat(&tmp, env->matrix, &yah);

	env->cam->r[0]->rd = sub_vectors(yah, env->cam->r[0]->rp);

	printf("x: %f y: %f z: %f\n", env->cam->r[0]->rd.x, env->cam->r[0]->rd.y, env->cam->r[0]->rd.z);
	printf("p:%p", &env->cam->r[0]->rd);

	if (!norm_vector(&env->cam->r[0]->rd))
		return (0);
	printf("cam:lz\n");
	return (1);
}
//
// int		buildray(t_env *env, int x, int y)
// {
// 	// if (env->cam->r)
// 	// 	clear_rays(env->cam->r);
// 	printf("supbebebuildray\n");
// 	if (!cam_ray(env, x, y))
// 		return (0);
// 	printf("sup\n");
// 	if (!env->cam->r[0])
// 		return (0);
// 	return (1);
// }
