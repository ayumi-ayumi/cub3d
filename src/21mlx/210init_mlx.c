#include "cub3d.h"
#include "exec.h"
#include <mlx.h>

/*initiate whatever possible to 0 or NULL*/
static void	nulling(t_game *screen)
{

}

int	init_window(t_game *screen)
{
	nulling(screen);
	screen->mlx = mlx_init();
	if (!screen->mlx)
		return(FAIL);

}
