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
# include "./../minilibx/mlx.h"

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
	int				r;
	int				f;
}					t_keys;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_pln
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			w;
	double			h;
	int				color;
}					t_pln;

typedef struct		s_sphr
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	int				color;
}					t_sphr;

typedef struct		s_cone
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	double			h;
	int				color;
}					t_cone;

typedef struct		s_col
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	double			h;
	int				color;
}					t_col;

typedef struct		s_lite
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	int				shine;
}					t_lite;

typedef struct		s_objects
{
	int				cpx;
	int				cpy;
	int				cpz;
	int				cdx;
	int				cdy;
	int				cdz;
	int				pln;
	int				s;
	int				con;
	int				col;
	int				lte;
	t_pln			**plns;
	t_sphr			**sphrs;
	t_cone			**cones;
	t_col			**cols;
	t_lite			**lites;
}					t_objects;

typedef struct		s_mapnums
{
	int				x;
	int				y;
	int				z;
	int				pls;
	int				sps;
	int				cns;
	int				cls;
	int				lts;
}					t_mapnums;

typedef struct		s_map
{
	t_mapnums		*nums;
	t_objects		*objs;
	int				***map;
}					t_map;

typedef struct		s_rayi
{
	int				p;
	int				s;
	int				cn;
	int				cl;
	int				lt;
}					t_rayi;

typedef struct		s_ray
{
	t_point			rp;
	t_point			rd;
}					t_ray;

typedef struct		s_objdis
{
	char			obj;
	int				obji;
	double			dis;
}					t_objdis;

typedef struct		s_cam
{
	int				camx;
	int				camy;
	double			mvspd;
	double			rtspd;
	t_point			pos;
	t_point			dir;
	t_point			horpl;
	t_point			vrtpl;
	t_objdis		**o_ds;
	t_ray			**r;
	int				color;
	int				lit;
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

#endif
