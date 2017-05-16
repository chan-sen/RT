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
	fd = open(argv[1], O_RDONLY);
	if (fd == 0)
		return (usage(2));
	map = check_map(fd);
	if (map == NULL)
		return (usage(3));
	return (fd);
}

t_env	*make_env(int argc, char **argv)
{
	t_env		*env;
	int			fd;

	fd = check(argc, argv);
	if (fd == 0)
		return (NULL);
	env = (t_env *)malloc(sizeof(t_env));
	env->map = make_map(fd);

	return (env);
}

void image_to(t_env *env)
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

int		rt_hook(t_env *env)
{
	image_to(env);
	raytrace(env);
	key_opts(env);
	return (1);
}

void rt(t_env *env)
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

// suedo bukkshit
//
// for (y = 0; y < WIN_HGT; y++)
// {for (x = 0; x < WIN_WDT; x++;)
// 	{
// 		1. > Build the ray from cam (rc)
// 		2. > Find all intersections of (rc) with objects
// 		3. > Find all intersection that lies closest to the eye
// 		4. > Compute the hit point where the ray hits this object,
// 				and the normal vector at that point
// 		5. > Find the color of the light returning to the eye
// 				along the ray from the point of intersections
// 		6. > Place the colot in the (rc) pixel
// 	}
