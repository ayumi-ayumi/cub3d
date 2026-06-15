#include "cub3d.h"
#include "exec.h"
#include <X11/keysym.h>/*for keycode*/
#include <math.h>/*for pi*/
#include <mlx.h>


/*moves with WDSA keys*/
static void	move_back_forth(t_play *play, int dir)
{
	play->pos.x = play->pos.x + dir * (play->dir.x * play->move.move_speed);
	play->pos.y = play->pos.y + dir * (play->dir.y * play->move.move_speed);
}

static void	move_side(t_play *play, char dir)
{
	t_vec	new_dir;
	char	factor;

	if (dir == 'l')
		factor = 1;
	if (dir == 'r')
		factor = 3;
	new_dir = turn_vec(play->dir, (double)factor * M_PI_2);
	play->pos.x = play->pos.x + (new_dir.x * play->move.move_speed);
	play->pos.y = play->pos.y + (new_dir.y * play->move.move_speed);
}

/*changes pos and dir according to key and recalculates and sends img to win*/
static void	handle_key_event(int	keycode, t_game *game)
{
	if (keycode == XK_Escape)
		cleanup_and_exit(game);
	if (keycode == XK_w || keycode == XK_Up)
		move_back_forth(&game->exec.play, 1);
	if (keycode == XK_s || keycode == XK_Down)
		move_back_forth(&game->exec.play, -1);
	if (keycode == XK_a)
		move_side(&game->exec.play, 'l');
	if (keycode == XK_d)
		move_side(&game->exec.play, 'r');
	if(keycode == XK_Left)
		game->exec.play.dir = turn_vec(game->exec.play.dir, M_PI_2);
	if(keycode == XK_Right)
		game->exec.play.dir = turn_vec(game->exec.play.dir, 3 * M_PI_2);
	raycast(game, &game->exec);
	mlx_put_image_to_window(game->mlx, game->win, game->exec.screen.img, 0, 0);
}


int	key_hook(int keycode, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	handle_key_event(keycode, game);
	return (0);
}

