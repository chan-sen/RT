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
