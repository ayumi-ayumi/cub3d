#include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <math.h>

static void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}

static t_vec	turn_vec(t_vec vec, double angle)
{
	double	cos;
	double	sin;
	t_vec	turned;

	
	cos = cos(angle);
	sin = sin(angle);

	turned.x = vec.x * cos - vec.y * sin;
	turned.y = vec.x * sin + vec.y * cos;
	return (turned);
}

static void	init_play_data(t_exec *exec)
{
	// exec.play.pos[0] = calc_pos(game, game.map.width, game.map.start_pos.col);
	// exec.play.pos[1] = calc_pos(game, game.map.height, game.map.start_pos.row);
	if (game.map.start_orientation == 'N')
		exec.play.dir = (t_vec){0, 1};
	if (game.map.start_orientation == 'S')
		exec.play.dir = (t_vec){0, 1};
	if (game.map.start_orientation == 'W')
		exec.play.dir = (t_vec){1, 0};
	if (game.map.start_orientation == 'E')
		exec.play.dir = (t_vec){-1, 0};
	exec.play.time = 0;
	exec.play.old_time = 0;
	exec.play.plane = turned(exec.play.dir, M_PI_2);
	exec.play.plane.x =* 0.66;
	exec.play.plane.y =* 0.66;
}

/*setup of screen and start game loop*/
int	execution(t_game *game)
{
	t_exec	exec;

	if (init_mlx(game, &exec) == FAIL || game->mlx == NULL
		return (cleanup_exec(game, &exec), FAIL);
	init_play_data(game, &exec);
	raycast(game, exec);
	return (cleanup_exec(game, &exec), SUCCESS);
}

/*
int	main(void)
{
	t_exec exec;
	t_game game;

	game.map.start_orientation = 'S';
	printf("dir: \(%d, %d\)\n", exec.play.dir.x, exec.play.dir.y);
	printf("time: %d, old_time: %d\n", exec.play.time, exec.play.old_time);
	printf("plane: \(%d,%d\)\n", exec.play.plane.x, exec.play.plane.y);
}*/
