
#include "./../includes/rt.h"

double	ft_invsqrtf(double a)
{
	return (1.0 / sqrt(a));
}

double	norm_vector(t_point *a)
{
	double	dist;
	double	tmp;

	printf("damn\n");
	printf("normx: %f y: %f z: %f\n", (*a).x, (*a).y, (*a).z);
	printf("hue%p\n", a);
	dist = dot_product(a, a);
	printf("hehe\n");
	if (dist == 0.0)
		return (dist);
	printf("damn\n");
	tmp = ft_invsqrtf(dist);
	printf("damn\n");
	*a = scale_vectors(tmp, *a);
	printf("damn\n");
	return (dist);
}

void matrix_identity(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void matrix_copy(double a[4][4], double b[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			b[i][j] = a[i][j];
			j++;
		}
		i++;
	}
}

void matrix_mult(double ma[4][4], double mb[4][4], double d[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			d[i][j] = ma[i][0] * mb[0][j] + ma[i][1] * mb[1][j]
				+ ma[i][2] * mb[2][j] + ma[i][3] * mb[3][j];
			j++;
		}
		i++;
	}
}

void matrix_translate(double matrix[4][4], double tx, double ty, double tz)
{
	double		tmat[4][4];
	double		tmp[4][4];

	matrix_identity(tmat);
	tmat[3][0] = tx;
	tmat[3][1] = ty;
	tmat[3][2] = tz;
	matrix_mult(matrix, tmat, tmp);
	matrix_copy(tmp, matrix);
}

void vct_mult_mat(t_point *a, double matrix[4][4], t_point *b)
{
	printf("vmmx: %f y: %f z: %f\n", a->x, a->y, a->z);
	printf("vmmx: %f y: %f z: %f\n", b->x, b->y, b->z);
	b->x = a->x * matrix[0][0] + a->y * matrix[1][0] + a->z * matrix[2][0] + matrix[3][0];
	b->y = a->x * matrix[0][1] + a->y * matrix[1][1] + a->z * matrix[2][1] + matrix[3][1];
	b->z = a->x * matrix[0][2] + a->y * matrix[1][2] + a->z * matrix[2][2] + matrix[3][2];
	printf("vmmx: %f y: %f z: %f\n", b->x, b->y, b->z);
}

void stuff_matrix(t_env *env)
{
	matrix_identity(env->matrix);
	matrix_translate(env->matrix, env->cam->pos.x, env->cam->pos.y, env->cam->pos.z);
}
