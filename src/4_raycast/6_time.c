#include "cub3d.h"
#include <mlx.h>
#include <sys/time.h>
/* populates move->time in milliseconds*/
static int	get_time(t_move *move)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != SUCCESS)
		return (FAIL);
	move->time = tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
	return (SUCCESS);
}


/*frame time is the time the frame has taken in seconds*/
/*speed is 5 squares per second and 3 radians per second*/
int	timing(t_move *move)
{
	move->old_time = move->time;
	if (get_time(move) != SUCCESS)
		return (FAIL);
	if (move->old_time == 0)
		move->frame_time = 0.0;
	else
		move->frame_time = (move->time - move->old_time) / 1000.0;
	move->steplength = (move->frame_time) * 5.0;
	move->radians = (move->frame_time) * 3.0;
	return (SUCCESS);
}
