#include "cub3d.h"
#include "exec.h"
#include "parser.h"/*for t_game*/
#include <mlx.h>

static void	cleanup_exec(t_exec *exec)
{
	if (exec->mlx)
		free_mlx(exec);
}

int	execution(t_game *game)
{
	t_exec	exec;

	if (init_mlx(game, &exec) == FAIL || !exec.mlx)
		return (cleanup_exec(&exec), FAIL);
	return (SUCCESS);
}
