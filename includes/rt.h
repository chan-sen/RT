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

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_vmath
{
	t_point			news;
	t_point			n;
	t_point			dist;
	double			tmp;
}					t_vmath;

typedef struct		s_pln
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			w;
	double			h;
	t_color			color;
	// double			refl;
}					t_pln;

typedef struct		s_sphr
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	t_color			color;
	// double			refl;
}					t_sphr;

typedef struct		s_cone
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	double			h;
	t_color			color;
	// double			refl;
}					t_cone;

typedef struct		s_col
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	double			r;
	double			h;
	t_color			color;
	// double			refl;
}					t_col;

typedef struct		s_lite
{
	int				xog;
	int				yog;
	int				zog;
	t_point			pos;
	t_color			lit;
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
	char			*obj;
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
	t_color			obcolor;
	t_color			pcolor;
	int				l;
	double			t;
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

void		rt(t_env *env);
int		rt_hook(t_env *env);
void		raytracer(t_env *env);
void	traceray(t_env *env, t_ray	*r, t_objdis **o_ds);

int	sphere_closest_intersect(double b, double disc, double *t);
int	sphere_intersect_check(t_sphr *s, t_ray *ray, double *t);
int obj_intersect_check(t_env *env, t_ray *ray, t_objdis *od);
t_objdis	*ray_intersects(t_env *env, t_ray *r, t_objdis **o_ds);
t_vmath		*sphere_intersect_spot(t_env *env, t_ray *r, t_objdis *o_d);
t_vmath		*intersection_spot(t_env *env, t_ray *r, t_objdis *od);

int			lower_dis(int i, int low, t_objdis **o_ds);
int			find_low_dis(int objs, t_objdis **o_ds);
int		dist_order_check(t_objdis **o_ds, t_mapnums *nums);
void reorder_dists(t_objdis **o_ds, t_mapnums *nums);

t_color		ray_obj_color(t_env *env, t_objdis *od);
t_ray	*build_light_ray(t_env *env, t_vmath *v);
t_color	add_colors(t_color pcolor, t_color lamb);
t_color	diffuse_lamb(t_lite *l, t_ray *r, t_point n, t_color c);
t_color	space(void);

int				objs_sum(t_mapnums *n);
int		ri_lessthan_objs(t_rayi *ri, t_mapnums *nums);
t_rayi		*set_rayi(void);

t_objdis	**obj_dists(t_env *env);
t_objdis		**find_objs(t_env *env, t_rayi *ri);
t_objdis		*obj_dis(char *str, double dis, int i);

t_point		point(double x, double y, double z);
t_point		point_itod(int x, int y, int z);
t_point		sub_vectors(t_point a, t_point b);
double		dot_product(t_point a, t_point b);
t_point		add_vectors(t_point a, t_point b);
t_point		scale_vectors(double c, t_point v);

void		buildray(t_env *env);
t_ray		*cam_ray(t_env *env);
t_point		cam_dir(t_env *env, t_point *cam);

t_point	hori_plane(t_point *dir);
t_point	vert_plane(t_point *dir);

t_env	*make_env(int argc, char **argv);
t_cam	*make_cam(t_map *map);
t_keys			*make_keys(void);
t_objects	*make_objects(t_mapnums *nums);
t_lite		**make_lites(int l);
t_col		**make_cols(int c);
t_cone		**make_cones(int c);
t_sphr		**make_sphrs(int s);
t_pln		**make_plns(int p);

void 		set_cam(char *str, t_objects *objects, t_point p);
void		set_sphr(char *str, t_sphr *sphr, t_point p);
void		set_cone(char *str, t_cone *cone, t_point p);
void		set_col(char *str, t_col *col, t_point p);
void		set_lite(char *str, t_lite *lite, t_point p);

t_map	*make_map(int argc, char **argv);
t_mapnums	*pull_nums(int fd);
int		**fill_layer(int fd, t_mapnums *nums, t_objects *objects);
int		*fill_row(char *line, t_mapnums *nums, t_objects *objects);
void	fill_object(char *str, t_objects *objects, t_point p);
void	pull_xyz(char *str, int *x, int *y, int *z);
void pull_lites(char *s, int *lts);
void pull_objs(char *s, int *sps, int *cns, int *cls);

int		key_press(int key, t_env *env);
int		key_release(int key, t_env *env);
void		key_optns(t_env *env);

int		check(int argc, char **argv);
int		usage(int err);
t_color		icolorto(int c);

void		image_to(t_env *env);
t_img		*make_img(void *mlx);
void		put_image_pixel(t_img *image, int x, int y, t_color color);


double			distform3d(t_point a, t_point b);

void	set4to0(int *a, int *b, int *c, int *d);
void	set3to0(int *a, int *b, int *c);

#endif
