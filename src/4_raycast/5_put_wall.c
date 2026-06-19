#include "cub3d.h"
#include "exec.h"
#include <stdint.h>

static unsigned int	get_color(t_play *play, int x, int y)
{
	unsigned int color;

	color = (unsigned int)x;
	color = (unsigned int)y;
	color =  16776960;
	if (play->side == DIR_NO)
		color = color / 4 ;
	if (play->side == DIR_SO)
		color = color / 3; 
	if (play->side == DIR_WE)
		color = color / 2; 
	return (color);
}


/*dummy function because i do not handle textures jet*/
void	put_wall(t_exec *exec, int *i, int tex_x, int x)
{
	unsigned int	color;

	color = get_color(&exec->play, tex_x, *i);
	while (*i < exec->draw_end)
	{
		put_pixel(&exec->scre, x, *i, color);
		*i += 1;
	}
	return ;
}



// static int get_texture_row();

// void	put_wall(t_exec *exec, int cam_x, int *i)
// {
// 	int	col;
// 	int	row;
//
// 	row = get_texture_row();
// 	put_pixel()	
// }
