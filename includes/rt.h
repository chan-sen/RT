/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:43:15 by chansen           #+#    #+#             */
/*   Updated: 2017/05/11 18:55:22 by chansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <time.h>
# include <math.h>

# include "./../libft/libft.h"
# include "./../minilibx/minilibx.h"

# define WIN_HGT	600
# define WIN_WDT	600

typedef struct		s_img
{
	void 			*img;
	char			*data;
	int				height;
	int				width;
	int				sizeline;
	int				bits;
	int				endian;
}					t_img;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				q;
	int				e;
	int				shft;
	int				spc;
	int				z;
	int				x;
}

typedef struct		s_sphr
{
	int				xog;
	int				yog;
	int				zog;
	double			x;
	double			y;
	double			z;
	double			r;
	int				color;
	int				shine;
	int				opac;
}					t_sphr;

typedef struct		s_cone
{
	int				xog;
	int				yog;
	int				zog;
	double			x;
	double			y;
	double			z;
	double			r;
	double			h;
	int				color;
	int				shine;
	int				opac;
}					t_cone;

typedef struct		s_col
{
	int				xog;
	int				yog;
	int				zog;
	double			x;
	double			y;
	double			z;
	double			r;
	double			h;
	int				color;
	int				shine;
	int				opac;
}					t_col;

typedef struct		s_lite
{
	int				xog;
	int				yog;
	int				zog;
	double			x;
	double			y;
	double			z;
	double			r;
	int				shine;

}					t_lite;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				***map;
	t_sphr			**sphrs;
	t_cone			**cones;
	t_col			**cols;
	t_lite			**lites;
}					t_map;

typedef struct		s_vctrs
{
	double			dx;
	double			dy;
	double			dz;
	double			hplx;
	double			hply;
	double			hplz;
	double			vplx;
	double			vply;
	double			vplz;
}					t_vctrs;

typedef struct		s_rays
{
	double			rpx;
	double			rpy;
	double			rpz;
	double			rdz;
	double			rdy;
	double			rdz;
}					t_rays;

typedef struct		s_cam
{
	int				mapx;
	int				mapy;
	int				mapz;
	double			posx;
	double			posy;
	double			posz;
	double			mvspd;
	double			rtspd;
	t_vctrs			*v;
	t_rays			*r[7];

}					t_cam;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	double			time;
	double			oldtime;
	double			frametime;
	t_map			*map;
	t_cam			*cam;
	t_img			*img;
	t_keys			*keys;
}					t_env;
