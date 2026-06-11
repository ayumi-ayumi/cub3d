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
