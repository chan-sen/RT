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

t_rayi		*set_rayi(void)
{
	t_rayi	*ri;

	ri = (t_rayi *)malloc(sizeof(t_rayi));
	ri->p = 0;
	ri->s = 0;
	ri->cn = 0;
	ri->cl = 0;
	ri->lt = 0;
	return (ri);
}

int				objs_sum(t_mapnums *n)
{
	return (n->pls + n->sps + n->cns + n->cls + n->lts);
}

double			distform3d(t_point a, t_point b)
{
	double		ret;

	ret = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2));
	return (ret);
}

void		raytracer(t_env *env)
{
	env->cam->o_ds = obj_dists(env);
	stuff_matrix(env);
	printf("mama\n");
	reorder_dists(env->cam->o_ds, env->map->nums);
	env->cam->camy = 0;
	while (env->cam->camy < WIN_HGT)
	{
		env->cam->camx = 0;
		while (env->cam->camx < WIN_WDT)
		{
			if (!cam_ray(env, env->cam->camx, env->cam->camy))
				return ;
			traceray(env, env->cam->r[0], env->cam->o_ds);
			put_image_pixel(env->image, env->cam->camx, env->cam->camy,
				env->cam->pcolor);
			env->cam->camx++;
		}
		env->cam->camy++;
	}
	/*

	clr_obj_dists(env->cam->o_ds);

	*/
}

int		rt_hook(t_env *env)
{
	image_to(env);
	raytracer(env);
	// key_optns(env);
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

int		main()
{
	t_env		*env;

	env = make_env();
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
// 		3. > Find intersection that lies closest to the eye
// 		4. > Compute the hit point where the ray hits this object,
// 				and the normal vector at that point
// 		5. > Find the color of the light returning to the eye
// 				along the ray from the point of intersections
// 		6. > Place the color in the (rc) pixel
// 	}
// }
