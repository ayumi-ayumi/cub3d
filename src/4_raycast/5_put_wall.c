#include "cub3d.h"
#include "exec.h"
#include <stdint.h>
#include <math.h>

/*
 * tex_per_pixel is amount of height one screen pixel represents
 * in the texture.
 */
void	put_wall(t_exec *exec, t_paint *paint)
{
	unsigned int	color;
	double			ratio;
	double			tex_per_pixel;
	int				side;

	ratio = (double)TEXTURE_HEIGHT / (double)exec->wall_height;
	tex_per_pixel = 0;
	side = (int)exec->play.side;
	paint->tex.row = 0;
	while (paint->screen.row < exec->draw_end)
	{
		paint->tex.row = (int)(floor(tex_per_pixel));
		color = get_pixel_colour(&exec->dir_texture[side],
				paint->tex.col, paint->tex.row);
		put_pixel(&exec->scre, paint->screen.col, paint->screen.row, color);
		tex_per_pixel += ratio;
		paint->screen.row += 1;
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
