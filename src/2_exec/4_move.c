#include "cub3d.h"
#include "exec.h"
#include <X11/keysym.h>/*for keycode*/
#include <math.h>/*for pi*/
#include <mlx.h>


/*moves with WDSA keys*/
static void	move_back_forth(t_game *game, t_play *play, int dir)
{
	t_vec	new;
	t_vec	check_radius;

	new.x = play->pos.x + dir * (play->dir.x * MOVESPEED);
	new.y = play->pos.y + dir * (play->dir.y * MOVESPEED);
	check_radius.x = new.x + dir * play->dir.x * COLLISION_RADIUS;
	check_radius.y = new.y + dir * play->dir.y * COLLISION_RADIUS;
	if (game->map.grid[(int)play->pos.y][(int)check_radius.x] == '0')
		play->pos.x = new.x;
	if (game->map.grid[(int)check_radius.y][(int)play->pos.x] == '0')
		play->pos.y = new.y;
}

static void	move_side(t_game *game, t_play *play, double angle)
{
	t_vec	new_dir;
	t_vec	new;
	t_vec	check_radius;

	new_dir = turn_vec(play->dir, angle);
	new.x = play->pos.x + (new_dir.x * MOVESPEED);
	new.y = play->pos.y + (new_dir.y * MOVESPEED);
	check_radius.x = new.x + (new_dir.x * COLLISION_RADIUS);
	check_radius.y = new.y + (new_dir.y * COLLISION_RADIUS);
	if (game->map.grid[(int)play->pos.y][(int)check_radius.x] == '0')
		play->pos.x = new.x;
	if (game->map.grid[(int)check_radius.y][(int)play->pos.x] == '0')
		play->pos.y = new.y;
}

/*changes pos and dir according to key and recalculates and sends img to win*/
static void	handle_key_event(int keycode, t_game *game)
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
	if (keycode == XK_Left)
		game->exec.play.dir = turn_vec(game->exec.play.dir, M_PI_2 * ROTSPEED);
	if (keycode == XK_Right)
		game->exec.play.dir = turn_vec(game->exec.play.dir,
				-1 * M_PI_2 * ROTSPEED);
	draw(game, &game->exec.scre);
}

int	key_hook(int keycode, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	handle_key_event(keycode, game);
	return (0);
}
