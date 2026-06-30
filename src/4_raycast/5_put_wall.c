#include "cub3d.h"
#include "exec.h"
#include <stdint.h>
#include <math.h>

/*
 * tex_y is amount of height one screen pixel represents
 * in the texture.
 */
void	put_wall(t_exec *exec, t_paint *paint)
{
	unsigned int	color;
	double			ratio;
	double			tex_y;

	ratio = (double)TEXTURE_HEIGHT / (double)exec->wall_height;
	tex_y = 0;
	while (exec->draw_start++ < 0)
		tex_y += ratio;
	while (paint->screen.row < SCREEN_HEIGHT
		&& paint->screen.row < exec->draw_end)
	{
		if (tex_y >= 0 && tex_y < TEXTURE_HEIGHT)
		{
			paint->tex.row = (int)(floor(tex_y));
			color = get_pixel_colour(&exec->wall_texture[(int)exec->play.side],
					paint->tex.col, paint->tex.row);
			img_pix_put(&exec->scre, paint->screen.col,
				paint->screen.row, color);
		}
		tex_y += ratio;
		paint->screen.row += 1;
	}
	return ;
}

/*
**  static int get_texture_row();
**  void	put_wall(t_exec *exec, int cam_x, int *i)
**  {
**  	int	col;
**  	int	row;
** 
**  	row = get_texture_row();
**  	put_pixel()
**  }
*/
