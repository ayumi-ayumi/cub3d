#include "cub3d.h"
#include "exec.h"
#include <math.h>

/*calculate which texture pixel col to display*/
static int	get_texture_x(t_play *play)
{
	int	tex_x;
	double	percent;
	double	wall_x;

	// tex_x = 0;
	// percent = play->side_dist.x - (int)play->side_dist.x;
	// tex_x = (int)(percent *  TEXTURE_WIDTH);
	if (play->side == WEST_EAST)
		wall_x = play->pos.y + play->perp_wall_dist * play->ray.y;
	else
		wall_x = play->pos.x + play->perp_wall_dist * play->ray.x;
	percent = wall_x - floor(wall_x);
	tex_x = (int)(percent * (double)TEXTURE_WIDTH);
	if ((play->side == WEST_EAST && play->ray.x > 0)
			|| (play->side == NORTH_SOUTH && play->ray.y < 0))
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	return (tex_x);
}

/*draw scre col from top down*/
void	draw_line(t_exec *exec, int x)
{
	int	i;
	int	tex_x;

	i = 0;
	tex_x = get_texture_x(&exec->play);
	while (i < exec->draw_start)
	{
		put_pixel(&exec->scre, x, i, exec->ceiling);
		i++;
	}
	while (i < exec->draw_end)
		put_wall(exec, &i, tex_x, x);
	while(i < SCREEN_HEIGHT)
	{
		put_pixel(&exec->scre, x, i, exec->floor);
		i++;
	}
	return ;
}
