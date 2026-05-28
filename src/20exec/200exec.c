#include "cub3d.h"
#include "exec.h"
#include <mlx.h>

static void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}

// static int	turn_vec(double vec[2], int angle)
// {
// }

static int	init_play_data(t_game *game, t_play *play)
{
	play.pos[0] = calc_pos(game, game.map.width, game.map.start_pos.col);
	play.pos[1] = calc_pos(game, game.map.height, game.map.start_pos.row);
	if (game.map.start_orientation == 'N')
		play.dir = (t_vec){0, 1};
	if (game.map.start_orientation == 'S')
		play.dir = (t_vec){0, 1};
	if (game.map.start_orientation == 'W')
		play.dir = (t_vec){1, 0};
	if (game.map.start_orientation == 'E')
		play.dir = (t_vec){-1, 0};
}

/*setup of screen and start game loop*/
int	execution(t_game *game)
{
	t_exec	exec;
	t_play	play;

	if (init_mlx(game, &exec) == FAIL || game->mlx == NULL
				|| init_play_data(game, &play!) == FAIL)
		return (cleanup_exec(game, &exec), FAIL);
	exec.play = play;

	raycast(game, exec);
	return (cleanup_exec(game, &exec), SUCCESS);
}
