#include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <math.h> /*for sin and cos*/

/*turning matrice turns counterclockwise even though in mirrored grid*/
t_vec	turn_vec(t_vec vec, double angle)
{
	double	cosi;
	double	sinu;
	t_vec	turned;

	cosi = cos(2 * M_PI - angle);
	sinu = sin(2 * M_PI - angle);
	turned.x = vec.x * cosi - vec.y * sinu;
	turned.y = vec.x * sinu + vec.y * cosi;
	return (turned);
}


t_vec add_vec(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vec subst_vec(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}


t_vec mult_vec(double factor, t_vec b)
{
	t_vec	result;

	result.x = factor * b.x;
	result.y = factor * b.y;
	return (result);
}

t_vec divt_vec(t_vec a, double dev)
{
	t_vec	result;

	if (dev == 0.0)
	{
		result.x = 10e23 * a.x;
		result.y = 10e23 * a.y;
	}
	else
	{
	result.x = a.x / dev;
	result.y = a.y / dev;
	}
	return (result);
}
