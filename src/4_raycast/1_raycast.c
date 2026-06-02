#include "cub3d.h"
#include "exec.h"

static void	dda(char **grid, t_play *play)
{
	while(play->hit == FALSE)
	{
		if (play->side_dist.x < play->side_dist.y)
		{
			play->side_dist.x += play->delta_dist.x;//why are we not incrementing the distance in the next step
			play->map.col += play->step.col;
			play->side = WEST_EAST;
		}
		else
		{
			play->side_dist.y += play->delta_dist.y;
			play->map.row += play->step.row;
			play->side = NORTH_SOUTH;
		}
		if (grid[(int)play->map.row][(int)play->map.col] > 0)
			play->hit = TRUE;
	}
	if (play->side == 0)
		play->perp_wall_dist = play->side_dist.x - play->delta_dist.x;
	else
		play->perp_wall_dist = play->side_dist.y - play->delta_dist.y;
}

static void	calc_height(t_exec *exec, int perp_wall_dist)
{
	int	line_height;

	line_height = (int)SCREEN_HEIGHT / perp_wall_dist;
	exec->draw_start = (-line_height / 2) +  (SCREEN_HEIGHT / 2);
	if (exec->draw_start < 0)
		exec->draw_start = 0;

	exec->draw_end = (line_height / 2) +  (SCREEN_HEIGHT / 2);
	if (exec->draw_end >= SCREEN_HEIGHT)
		exec->draw_end = SCREEN_HEIGHT - 1;
	//TODO null all play values when initializing
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
		dda(game->map.grid, exec->play.perp_wall_dist);
		calc_height(&exec, &exec->play);
		draw_line(game);
		x++;
	}
	return (SUCCESS);
}
