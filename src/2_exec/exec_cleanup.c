#include "cub3d.h"
#include "exec.h"


void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}
