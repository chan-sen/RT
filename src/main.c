/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 20:01:50 by chansen           #+#    #+#             */
/*   Updated: 2017/05/11 20:01:51 by chansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rt.h"

int		usage(int err)
{
	if (err == 1)
		ft_putstr("usage: ./RT <filepath>\n");
	if (err == 2)
		ft_putstr("error: filepath invalid\n");
	return (0);
}

int		check(int argc, char **argv)
{
	char	***map;
	int		fd;

	if (argc != 2)
		return (usage(1));
	fd = open(argc[1], O_RDONLY);
	if (fd == 0)
		return (NULL);
	return (fd);
}

t_point	hori_plane(t_point pos, t_point dir)
{
	t_point		ret;

	ret.x = ;
	ret.y = ;
	ret.z = ;
	return (ret);
}

t_point	vert_plane(t_point pos, t_point dir)
{
	t_point		ret;

	ret.x = ;
	ret.y = ;
	ret.z = ;
	return (ret);
}

t_cam	*make_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->camx = 0;
	cam->camy = 0;
	cam->rfract = 0;
	cam->rflect = 0;
	cam->mvspd = 5.0;
	cam->rtspd = 3.0;
	cam->pos = point_itod(map->cpx, map->cpy, map->cpz);
	cam->dir = point_itod(map->cdx, map->cdy, map->cdz);
	cam->horpl = hori_plane(cam->pos, cam->dir);
	cam->vrtpl = vert_plane(cam->pos, cam->dir);
	cam->r = NULL;
	return (NULL);
}

t_env	*make_env(int argc, char **argv)
{
	t_env		*env;
	int			fd;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = NULL;
	env->win = NULL;
	env->time = 0;
	env->oldtime = 0;
	env->frametime = 0;
	env->map = make_map();
	env->cam = make_cam(env->map);
	env->img = NULL;
	env->keys = make_keys();
	return (env);
}

t_img		make_img(void *mlx)
{
	t_img	image;

	image.img = mlx_new_image(mlx, WIN_WDT, WIN_HGT);
	image.data = mlx_get_data_addr(image.img, &image.bits,
		&image.sizeline, &image.endian);
	image.height = WIN_HGT;
	image.width = WIN_WDT;
	return (image);
}

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

void		key_optns(t_env *env)
{
	if (env);
}

void buildray(t_env *env)
{
	if (env->cam->r)
		clear_rays(env->cam->r);

	env->cam->r = (t_rays **)malloc(sizeof(t_rays *)
		* (env->cam->rflect + env->cam->rfract));
}

void		raytracer(t_env *env)
{
	env->cam->camy = 0;
	while (env->cam->camy < WIN_HGT)
	{
		env->cam->camx = 0;
		while (env->cam->camx < WIN_WDT)
		{
			buildray(env);
			traceray(env);
			env->cam->camx++;
		}
		env->cam->camy++;
	}

}

int		rt_hook(t_env *env)
{
	image_to(env);
	raytracer(env);
	key_optns(env);
	return (1);
}

void		rt(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_WDT, WIN_HGT, "chansen ~ RT");
	mlx_loop_hook(env->mlx, rt_hook, env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 3, 0, key_release, env);
	mlx_hook(env->win, 17, 0, exit_hook, env);
	mlx_loop(env->mlx);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = make_env(argc, argv);
	if (env)
		rt(env);
	return (0);

}

// psuedo bukkshit
//
// for (y = 0; y < WIN_HGT; y++)
// {
// 	for (x = 0; x < WIN_WDT; x++)
// 	{
// 		1. > Build the ray from cam (rc)
// 		2. > Find all intersections of (rc) with objects
// 		3. > Find all intersection that lies closest to the eye
// 		4. > Compute the hit point where the ray hits this object,
// 				and the normal vector at that point
// 		5. > Find the color of the light returning to the eye
// 				along the ray from the point of intersections
// 		6. > Place the color in the (rc) pixel
// 	}
// }
