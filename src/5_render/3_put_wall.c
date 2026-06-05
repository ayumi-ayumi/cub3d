#include "cub3d.h"
#include "exec.h"
#include <stdint.h>

/*dummy function because i do not handle textures jet*/
void	put_wall(t_exec *exec, int cam_x, int *i)
{
	while (*i < exec->draw_end)
	{
		put_pixel(&exec->screen, cam_x, *i, 555444333);
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
