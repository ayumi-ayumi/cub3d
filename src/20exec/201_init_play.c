#include "cub3d.h"/*for t_game and Macros*/
#include "exec.h"/*for t_exec*/
#include <math.h> /*for sin and cos*/

/*turning matrice turns counterclockwise*/
static t_vec	turn_vec(t_vec vec, double angle)
{
	double	cosi;
	double	sinu;
	t_vec	turned;

	cosi = cos(angle);
	sinu = sin(angle);
	turned.x = vec.x * cosi - vec.y * sinu;
	turned.y = vec.x * sinu + vec.y * cosi;
	return (turned);
}

/*populates the game struct with initial data, val 0 can be -0*/
int	init_play_data(t_game *game, t_exec *exec)
{
	// exec.play.pos[0] = calc_pos(game, game.map.:uwidth, game.map.start_pos.col);
	// exec.play.pos[1] = calc_pos(game, game.map.height, game.map.start_pos.row);
	if (game->map.start_orientation == 'N')
		exec->play.dir = (t_vec){0, 1};
	else if (game->map.start_orientation == 'S')
		exec->play.dir = (t_vec){ 0, -1};
	else if (game->map.start_orientation == 'W')
		exec->play.dir = (t_vec){-1, 0};
	else if (game->map.start_orientation == 'E')
		exec->play.dir = (t_vec){1, 0};
	else
		return (FAIL);
	exec->play.time = 0;
	exec->play.old_time = 0;
	exec->play.plane = turn_vec(exec->play.dir, -1 * M_PI_2);
	exec->play.plane.x = exec->play.plane.x * 0.66;
	exec->play.plane.y = exec->play.plane.y * 0.66;
	return (SUCCESS);
}

/*
 * Test for init_play_data
*/

/*
 * #include <stdio.h>
 * int	main(void)
 * {
 * 	t_exec exec;
 * 	t_game game;
 *
 * 	game.map.start_orientation = 'S';
 * 	init_play_data(&game, &exec);
 * 	printf("dir: ( %.2lf, %.2lf )\n", exec.play.dir.x, exec.play.dir.y);
 * 	printf("time: %.2lf, old_time: %.2lf\n", exec.play.time, exec.play.old_time);
 * 	printf("plane: (%.2lf,%.2lf)\n", exec.play.plane.x, exec.play.plane.y);
 * }
*/
