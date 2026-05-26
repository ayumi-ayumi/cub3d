#include "cub3d.h"
#include "exec.h"
#include <mlx.h>

static void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}

int	execution(t_game *game)
{
	t_exec	exec;

	if (init_mlx(game, &exec) == FAIL || !game->mlx)
		return (cleanup_exec(game, &exec), FAIL);
	cleanup_exec(game, &exec);
	return (SUCCESS);
}
