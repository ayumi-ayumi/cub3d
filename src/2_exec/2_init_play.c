#include "cub3d.h"/*for t_game and Macros*/
#include "exec.h"/*for t_exec*/
#include "libft.h"/*for ft_bezero*/
#include <math.h> /*for sin and cos*/

/*converts int[3] to int by shifting bits to their position*/
static unsigned int	convert_rgb(int array[3])
{
	unsigned int	rgb;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (array[0] < 0 || array[1] < 0 || array[2] < 0)
		return (-1);
	r = (unsigned int)array[0];
	g = (unsigned int)array[1];
	b = (unsigned int)array[2];
	rgb = r << 16 | g << 8 | b;
	return (rgb);
}

/*populates the game struct with initial data, val 0 can be -0*/
int	init_play_data(t_game *game, t_exec *exec)
{
	ft_bzero(&exec->play, sizeof(t_play));
	exec->play.pos.x = (double)game->map.start_pos.col + 0.5;
	exec->play.pos.y = (double)game->map.start_pos.row + 0.5;
	if (game->map.start_orientation == 'N')
		exec->play.dir = (t_vec){0, -1};
	else if (game->map.start_orientation == 'S')
		exec->play.dir = (t_vec){0, 1};
	else if (game->map.start_orientation == 'W')
		exec->play.dir = (t_vec){-1, 0};
	else if (game->map.start_orientation == 'E')
		exec->play.dir = (t_vec){1, 0};
	else
		return (FAIL);
	exec->play.plane = turn_vec(exec->play.dir, 3 * M_PI_2);
	exec->play.plane = mult_vec(0.66, exec->play.plane);
	exec->ceiling = convert_rgb(game->config.ceiling);
	exec->floor = convert_rgb(game->config.floor);
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
