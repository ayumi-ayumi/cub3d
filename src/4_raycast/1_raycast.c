#include "cub3d.h"
#include "exec.h"

static void	dda(t_game *game, t_exec *exec, t_play *play)
{

}

/*loop through every pixel col of the screen*/
int	raycast(t_game *game, t_exec *exec)
{
	int		x;
	double	cam_x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_x = 2 * (double)x / (double)SCREEN_WIDTH - 1;
		calc_start_values(&exec->play, cam_x);
		while (exec->play.hit == 0)
			dda(game, exec, &exec->play);
		x++;
	}
	return (SUCCESS);
}
