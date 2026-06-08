#include "cub3d.h"
#include "exec.h"

/*calculate which texture pixel col to display*/
static int	get_texture_x(t_play *play)
{
	int	tex_x;
	double	percent;

	tex_x = 0;
	percent = play->side_dist.x - (int)play->side_dist.x;
	tex_x = (int)(percent *  IMG_WIDTH);
	return (tex_x);
}

/*draw screen col from top down*/
void	draw_line(t_exec *exec)
{
	int	i;
	int	tex_x;

	i = 0;
	tex_x = get_texture_x(&exec->play);
	while (i < exec->draw_start - 1)
	{
		put_pixel(&exec->screen, exec->play.cam_x, i, exec->ceiling);
		i++;
	}
	while (i < exec->draw_end)
		put_wall(exec, &i, tex_x);
	while(i < SCREEN_HEIGHT)
	{
		put_pixel(&exec->screen, exec->play.cam_x, i, exec->floor);
		i++;
	}
	return ;
}
