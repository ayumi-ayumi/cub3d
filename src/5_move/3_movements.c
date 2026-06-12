#include "cub3d.h"
#include "exec.h"
#include <math.h>/*for pi */

/*moves with WDSA keys*/
void	move_on(t_play *play)
{
	play->pos.x = play->pos.x + (play->dir.x * play->move.move_speed);
	play->pos.y = play->pos.y + (play->dir.y * play->move.move_speed);
}

void	move_back(t_play *play)
{
	play->pos.x = play->pos.x - (play->dir.x * play->move.move_speed);
	play->pos.y = play->pos.y - (play->dir.y * play->move.move_speed);
}


void	move_right(t_play *play)
{
	t_vec	right;

	right = turn_vec(play->dir, 3 * M_PI_2);
	play->pos.x = play->pos.x + (right.x * play->move.move_speed);
	play->pos.y = play->pos.y + (right.y * play->move.move_speed);
}


void	move_left(t_play *play)
{
	t_vec	left;

	left = turn_vec(play->dir,  M_PI_2);
	play->pos.x = play->pos.x + (left.x * play->move.move_speed);
	play->pos.y = play->pos.y + (left.y * play->move.move_speed);
}


