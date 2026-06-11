#include "cub3d.h"
#include <sys/time.h>

static int	get_time(t_move *move)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != SUCCESS)
		return (FAIL);
	move->time = tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
	return (SUCCESS);
}


/*frame time is the time the frame has taken in seconds*/
int	timing(t_move *move)
{
	move->old_time = move->time;
	if (get_time(move) != SUCCESS)
		return (FAIL);
	move->frame_time = (move->time - move->old_time) / 1000.0;
	return (SUCCESS);
}
