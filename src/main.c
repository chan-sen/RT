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

void more_refract(t_env *env)
{
	if (env->cam->rfract >= 0 && (env->cam->rfract + env->cam->rflect) < 8)
		env->cam->rfract++;
}

void more_reflect(t_env *env)
{
	if (env->cam->rflect >= 0 && (env->cam->rfract + env->cam->rflect) < 8)
		env->cam->rflect++;
}

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
	if (env->keys->r == 1)
		more_refract(env);
	if (env->keys->f == 1)
		more_reflect(env);
}

t_point		cam_dir(t_env *env, t_point *cam, int x, int y)
{
	t_point	cd;


	cd = point();
	return (cd);
}

t_ray		*cam_ray(t_env *env, int x, int y)
{
	t_ray	*cr;

	cr = (t_ray *)malloc(sizeof(t_ray));
	cr->rp = point(env->cam->pos.x, env->cam->pos.y, env->cam->pos.z);
	cr->rd = cam_dir(env, &cr->rp, x, y);
	return (cr);
}

void buildray(t_env *env)
{
	if (env->cam->r)
		clear_rays(env->cam->r);
	env->cam->r = (t_rays **)malloc(sizeof(t_rays *)
		* 1 + (env->cam->rflect + env->cam->rfract));
	env->cam->r[0] = cam_ray(env->cam->camx, env->cam->camy);
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
