#include "cub3d.h"
#include "exec.h"
#include <mlx.h>

static void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}

/*setup of screen and start game loop*/
int	execution(t_game *game)
{
	t_exec	exec;

	if (init_mlx(game, &exec) == FAIL || game->mlx == NULL
			|| init_play_data(game, &exec) == FAIL)
		return (cleanup_exec(game, &exec), FAIL);
	init_play_data(game, &exec);
	raycast(game, exec);
	return (cleanup_exec(game, &exec), SUCCESS);
	return (SUCCESS);
}

