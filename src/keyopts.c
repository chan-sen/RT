
#include "./../includes/rt.h"

void		key_optns(t_env *env)
{
	if (env->keys->w == 1)
		forward(env);
	if (env->keys->a == 1)
		l_rot(env);
	if (env->keys->s == 1)
		backwards(env);
	if (env->keys->d == 1)
		r_rot(env);
	if (env->keys->q == 1)
		l_slide(env);
	if (env->keys->e == 1)
		r_slide(env);
	if (env->keys->shft == 1)
		up(env);
	if (env->keys->spc == 1)
		down(env);
	if (env->keys->z == 1)
		z_i(env);
	if (env->keys->x == 1)
		z_o(env);
}
