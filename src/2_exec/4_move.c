#include "cub3d.h"
#include "exec.h"
#include <X11/keysym.h>/*for keycode*/
#include <math.h>/*for pi*/
#include <mlx.h>

/*moves with WDSA keys*/
static void	move_back_forth(t_game *game, t_play *play, int dir)
{
	t_vec new;

	// play->pos.x = play->pos.x + dir * (play->dir.x * play->move.steplength);
	// play->pos.y = play->pos.y + dir * (play->dir.y * play->move.steplength);
	new.x = play->pos.x + dir * (play->dir.x * MOVESPEED);
	new.y = play->pos.y + dir * (play->dir.y * MOVESPEED);
	if (game->map.grid[(int)play->pos.y][(int)new.x] == '0')
		play->pos.x = new.x;
	if (game->map.grid[(int)new.y][(int)play->pos.x] == '0')
		play->pos.y = new.y;
}

static void	move_side(t_game *game, t_play *play, double angle)
{
	t_vec	new_dir;
	t_vec	new;

	new_dir = turn_vec(play->dir, angle);
	// play->pos.x = play->pos.x + (new_dir.x * play->move.steplength);
	// play->pos.y = play->pos.y + (new_dir.y * play->move.steplength);
	new.x = play->pos.x + (new_dir.x * MOVESPEED);
	new.y = play->pos.y + (new_dir.y * MOVESPEED);
	if (game->map.grid[(int)play->pos.y][(int)new.x] == '0')
		play->pos.x = new.x;
	if (game->map.grid[(int)new.y][(int)play->pos.x] == '0')
		play->pos.y = new.y;
}

/*changes pos and dir according to key and recalculates and sends img to win*/
static void	handle_key_event(int	keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		free_entire_mlx(game);
		cleanup_and_exit(game);
	}
	if (keycode == XK_w || keycode == XK_Up)
		move_back_forth(game, &game->exec.play, 1);
	if (keycode == XK_s || keycode == XK_Down)
		move_back_forth(game, &game->exec.play, -1);
	if (keycode == XK_a)
		move_side(game, &game->exec.play, M_PI_2);
	if (keycode == XK_d)
		move_side(game, &game->exec.play, 3 * M_PI_2);
	if(keycode == XK_Left)
		game->exec.play.dir = turn_vec(game->exec.play.dir, M_PI_2 * ROTSPEED);
	if(keycode == XK_Right)
		game->exec.play.dir = turn_vec(game->exec.play.dir, 2 * M_PI - M_PI_2 * ROTSPEED);
	draw(game, &game->exec.play.move, &game->exec.scre);
}


int	key_hook(int keycode, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	handle_key_event(keycode, game);
	return (0);
}

