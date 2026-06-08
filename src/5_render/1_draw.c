#include "cub3d.h"
#include "exec.h"
/*draw screen col from top down*/
void	draw_line(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec->draw_start - 1)
	{
		put_pixel(&exec->screen, exec->play.cam_x, i, exec->ceiling);
		i++;
	}
	while (i < exec->draw_end)
		put_wall(exec, &i);
	while(i < SCREEN_HEIGHT)
	{
		put_pixel(&exec->screen, exec->play.cam_x, i, exec->floor);
		i++;
	}
	return ;
}
