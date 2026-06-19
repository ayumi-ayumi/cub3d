#include "cub3d.h"
#include "exec.h"
#include "libft.h"
#include <math.h>

/*calculate which texture pixel col to display*/
static void	get_texture_x(t_play *play, t_paint *paint)
{
	double	wall_x;
	double	percent;

	if (play->side == DIR_WE|| play->side == DIR_EA)
		wall_x = play->pos.y + play->perp_wall_dist * play->ray.y;
	else
		wall_x = play->pos.x + play->perp_wall_dist * play->ray.x;
	percent = wall_x - floor(wall_x);
	paint->tex.col = (int)(percent * (double)TEXTURE_WIDTH);
	if (((play->side == DIR_WE || play->side == DIR_EA) && play->ray.x > 0)
			|| ((play->side == DIR_NO || play->side == DIR_SO) && play->ray.y < 0))
		paint->tex.col = TEXTURE_WIDTH - paint->tex.col - 1;
}


/*draw scre col from top down*/
void	draw_line(t_exec *exec, int x)
{
	t_paint paint;

	ft_bzero(&paint, sizeof(t_paint));
	paint.screen.col = x;
	while (paint.screen.row < exec->draw_start)
		get_texture_x(&exec->play, &paint);
	{
		put_pixel(&exec->scre, x, paint.screen.row, exec->ceiling);
		paint.screen.row++;
	}
	while (paint.screen.row < exec->draw_end)
		put_wall(exec, &paint.screen.row, paint.tex.col, x);
	while(paint.screen.row < SCREEN_HEIGHT)
	{
		put_pixel(&exec->scre, x, paint.screen.row, exec->floor);
		paint.screen.row++;
	}
	return ;
}
