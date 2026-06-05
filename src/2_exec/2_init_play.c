#include "cub3d.h"/*for t_game and Macros*/
#include "exec.h"/*for t_exec*/
#include <math.h> /*for sin and cos*/

/*turning matrice turns counterclockwise even though in mirrored grid*/
static t_vec	turn_vec(t_vec vec, double angle)
{
	double	cosi;
	double	sinu;
	t_vec	turned;

	cosi = cos(2 * M_PI - angle);
	sinu = sin(2 * M_PI - angle);
	turned.x = vec.x * cosi - vec.y * sinu;
	turned.y = vec.x * sinu + vec.y * cosi;
	return (turned);
}

/*converts int[3] to int by shifting bits to their position*/
static int	convert_rgb(int array[3])
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	
	r = array[0];
	g = array[1];
	b = array[2];
	if (r < 0 || g < 0 || b < 0)
		return (-1);
	rgb = r << 16 | g << 8 | b;
	return (rgb);
}

/*populates the game struct with initial data, val 0 can be -0*/
int	init_play_data(t_game *game, t_exec *exec)
{
	exec->play.pos.x = (double)game->map.start_pos.col + 0.5;
	exec->play.pos.y = (double)game->map.height - (double)game->map.start_pos.row + 0.5;
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
	exec->ceiling = convert_rgb(game->config.ceiling);
	exec->floor = convert_rgb(game->config.floor);
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
