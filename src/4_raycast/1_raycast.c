#include "cub3d.h"
#include "exec.h"

static void	dda(char **grid, t_play *play)
{
	while(play->hit == FALSE)
	{
		if (play->side_dist.x < play->side_dist.y)
		{
			play->side_dist.x += play->delta_dist.x;//why are we not incrementing the distance in the next step
			play->map.i += play->step.i;
			play->side = 0;
		}
		else
		{
			play->side_dist.y += play->delta_dist.y;
			play->map.j += play->step.j;
			play->side = 1;
		}
		if (grid[play->map.i][play->map.j] > 0)
			play->hit = TRUE;
	}
	if (play->side == 0)
		play->perp_wall_dist = play->side_dist.x - play->delta_dist.x;
	else
		play->perp_wall_dist = play->side_dist.y - play->delta_dist.y;
}

/*loop through every pixel col of the screen*/
int	raycast(t_game *game, t_exec *exec)
{
	int		x;
	double	cam_x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_x = 2 * (double)x / (double)SCREEN_WIDTH - 1;
		calc_start_values(&exec->play, cam_x);
		dda(game->map.grid, &exec->play);
		x++;
	}
	return (SUCCESS);
}
