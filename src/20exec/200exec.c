// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>

int	execution(t_game *game)
{
	if (init_mlx(game) == FAIL || !game->mlx)
		return (FAIL);
	if (start_graphics(game) == FAIL)
		return (FAIL);
	// cleanup_exec(game, &exec);
	return (SUCCESS);
}
