
#include "./../includes/rt.h"

void		put_image_pixel(t_img image, int x, int y, int color)
{
	int			b;

	if (x < 0 || y < 0 || x >= image.width || y >= image.height)
		return ;
	b = (4 * x) + (y * image.sizeline);
	image.data[b++] = color & 0xFF;
	image.data[b++] = (color >> 8) & 0xFF;
	image.data[b++] = (color >> 16) & 0xFF;
}

void		image_to(t_env *env)
{
	env->oldtime = env->time;
	env->time = clock();
	env->frame = (env->time - env->oldtime) / CLOCKS_PER_SEC;
	mlx_clear_window(env->mlx, env->win);
	if (env->image.img)
		mlx_put_image_to_window(env->mlx, env->win, env->image.img, 0, 0);
	mlx_string_put(env->mlx, env->win, 0, 0, 0xFFFFFF,
		ft_itoa((int)(1 / env->frametime)));
	env->image = make_img(env->mlx);
	env->cam->mvspd = (env->frametime * 6.0);
	env->cam->rtspd = (env->frametime * 3.0);
}
