
#include "./includes/rt.h"

int		key_press(int key, t_env *env)
{
	if (key == 13)
		env->keys->w = 1;
	if (key == 0)
		env->keys->a = 1;
	if (key == 1)
		env->keys->s = 1;
	if (key == 2)
		env->keys->d = 1;
	if (key == 12)
		env->keys->q = 1;
	if (key == 14)
		env->keys->e = 1;
	return (key);
}

int		key_release(int key, t_env *env)
{
	if (key == 13)
		env->keys->w = 0;
	if (key == 0)
		env->keys->a = 0;
	if (key == 1)
		env->keys->s = 0;
	if (key == 2)
		env->keys->d = 0;
	if (key == 12)
		env->keys->q = 0;
	if (key == 14)
		env->keys->e = 0;
	return (key);
}

t_keys			*make_keys(void)
{
	t_keys		*key;

	key = (t_keys *)malloc(sizeof(t_keys));
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
	return (key);
}
