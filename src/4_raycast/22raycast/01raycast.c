#include "cub3d.h"
#include "exec.h"
#include <math.h>

static void	raypos(t_play *play)
{
	int		x;
	double	cam_x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_x = 2 * (double)x / (double)SCREEN_WIDTH  - 1;
		play->ray.x = play->dir.x + play->plane.x * cam_x;
		play->ray.y = play->dir.y + play->plane.y * cam_x;
		play->map.col = (int)(play->pos.x);
		play->map.row = (int)(play->pos.y);
		if (play->ray.x == 0)
			play->delta_dist.x = 1e30;
		else
			play->delta_dist.y = fabs(1 / play->ray.x);
		if (play->ray.y == 0)
			play->delta_dist.y = 1e30;
		else
			play->delta_dist.y = fabs(1 / play->ray.y);
		x++;
	}
}

int	raycast(t_exec *exec)
{
	raypos(&exec->play);
	return (SUCCESS);
}
