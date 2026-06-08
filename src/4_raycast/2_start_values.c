#include "cub3d.h"
#include <math.h>

static void	calc_delta_dist(t_play *play)
{
	if (play->ray.x == 0)
		play->delta_dist.x = 1e30;
	else
		play->delta_dist.x = fabs(1 / play->ray.x);
	if (play->ray.y == 0)
		play->delta_dist.y = 1e30;
	else
		play->delta_dist.y = fabs(1 / play->ray.y);
}

static void	calc_side_dist(t_play *play)
{
	if (play->ray.x < 0)
	{
		play->step.col = -1;
		play->side_dist.x = (play->pos.x - play->map.col) * play->delta_dist.x;
	}
	else
	{
		play->step.col = 1;
		play->side_dist.x = (1 + play->map.col - play->pos.x) \
		* play->delta_dist.x;
	}
	if (play->ray.y < 0)
	{
		play->step.row = -1;
		play->side_dist.y = (play->pos.y - play->map.row) * play->delta_dist.y;
	}
	else
	{
		play->step.row = 1;
		play->side_dist.y = (1 + play->map.row - play->pos.y) * \
		play->delta_dist.y;
	}
}

/*calculate initial vectors and positions for dda*/
void	calc_start_values(t_play *play)
{
	play->ray.x = play->dir.x + play->plane.x * play->cam_x;
	play->ray.y = play->dir.y + play->plane.y * play->cam_x;
	play->map.col = (int)(play->pos.x);
	play->map.row = (int)(play->pos.y);
	play->hit = 0;
	calc_delta_dist(play);
	calc_side_dist(play);
}
