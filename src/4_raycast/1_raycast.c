#include "cub3d.h"
#include "exec.h"

static void	calc_perp_wall_dist(t_play *play)
{
	if (play->side == DIR_WE || play->side == DIR_EA)
		play->perp_wall_dist = play->side_dist.x - play->delta_dist.x;
	else
		play->perp_wall_dist = play->side_dist.y - play->delta_dist.y;
}

static void	dda(char **grid, t_play *play)
{
	while(play->wall_hit == FALSE)
	{
		if (play->side_dist.x < play->side_dist.y)
		{
			play->side_dist.x += play->delta_dist.x;
			play->map.col += play->step.col;
			if (play->ray.x > 0)
				play->side = DIR_WE;
			else
			 play->side = DIR_EA;
		}
		else
		{
			play->side_dist.y += play->delta_dist.y;
			play->map.row += play->step.row;
			if (play->ray.y > 0)
				play->side = DIR_SO; 
			else
			 play->side = DIR_NO;
		}
		if (grid[(int)play->map.row][(int)play->map.col] == '1')
			play->wall_hit = TRUE;
	}
	calc_perp_wall_dist(play);
}

static void	calc_height(t_exec *exec, double perp_wall_dist)
{
	if (perp_wall_dist < 0.01)
		exec->wall_height = 100 * SCREEN_HEIGHT;
	else
		exec->wall_height = (unsigned int)((double)SCREEN_HEIGHT /perp_wall_dist);
	exec->draw_start = -(exec->wall_height / 2) +  (SCREEN_HEIGHT / 2);
	if (exec->draw_start < 0)
		exec->draw_start = 0;
	exec->draw_end = (exec->wall_height / 2) +  (SCREEN_HEIGHT / 2);
	if (exec->draw_end >= SCREEN_HEIGHT)
		exec->draw_end = SCREEN_HEIGHT;
}

/*loop through every pixel col of the scre*/
int	raycast(t_game *game, t_exec *exec)
{
	int		x;
	double	cam_x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_x = 2.0 * (double)x / (double)SCREEN_WIDTH - 1.0;
		calc_start_values(&exec->play, cam_x);
		dda(game->map.grid, &exec->play);
		calc_height(exec, exec->play.perp_wall_dist);
		draw_line(exec, x);
		x++;
	}
	draw_minimap(game);
	// draw_mini_map(&game->map, &exec->play, &exec->scre);
	return (SUCCESS);
}
