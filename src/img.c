
#include "./../includes/rt.h"

void		put_image_pixel(t_img *image, int x, int y, t_color color)
{
	int			b;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	b = (4 * x) + (y * image->sizeline);
	image->data[b++] = (unsigned char)fmin(color.r * 255.0, 255.0);
	image->data[b++] = (unsigned char)fmin(color.g * 255.0, 255.0);
	image->data[b++] = (unsigned char)fmin(color.b * 255.0, 255.0);
}

t_img		*make_img(void *mlx)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	image->img = mlx_new_image(mlx, WIN_WDT, WIN_HGT);
	image->data = mlx_get_data_addr(image->img, &image->bits,
		&image->sizeline, &image->endian);
	image->height = WIN_HGT;
	image->width = WIN_WDT;
	return (image);
}

void		image_to(t_env *env)
{
	env->oldtime = env->time;
	env->time = clock();
	env->frametime = (env->time - env->oldtime) / CLOCKS_PER_SEC;
	mlx_clear_window(env->mlx, env->win);
	if (env->image)
		mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 0, 0, 0xFFFFFF,
		ft_itoa((int)(1 / env->frametime)));
	env->image = make_img(env->mlx);
	env->cam->mvspd = (env->frametime * 6.0);
	env->cam->rtspd = (env->frametime * 3.0);
}
