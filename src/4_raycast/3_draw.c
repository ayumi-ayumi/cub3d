#include "cub3d"
#include "exec.h"

static void	put_pixel(t_data *img, int x, int y, int colour)
{
	int	pixel;

	pixel = y * (img->line_length / 4) + x;
	img->addr[pixel] = colour;
}

static void	put_wall(t_exec *exec, int cam_x, int *i)

/*draw screen col from top down*/
void	draw_line(t_exec *exec, int cam_x)
{
	int	i;

	i = 0;
	while (i < exec->draw_start - 1)
	{
		put_pixel(&exec->img, cam_x, i, exec->ceiling);
		i++;
	}
	while (i < exec->draw_end)
		put_wall(exec, cam_x, &i);
	while(i < SCREEN_HEIGHT)
	{
		put_pixel(&exec->img, cam_x, i, exec->floor);
		i++;
	}
	return ;
}
