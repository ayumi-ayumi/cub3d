#include "cub3d.h"
#include "exec.h"
#include "parser.h"/*for t_game*/
#include <mlx.h>

static void	cleanup_exec(t_game *game)
{
	if (game->mlx)
		free_mlx(game);

}

int	execution(t_game *game) {
	t_exec	exec;

	if (init_mlx(game) == FAIL || !exec.mlx)
		return (cleanup_exec(&exec), FAIL);
	return (SUCCESS);
}
