#include "cub3d.h"
#include "exec.h"
#include <X11/keysym.h>/*for keycode*/

static int	tap_key(int	keycode, t_game *game)
{
	if (keycode == XK_Escape)
		cleanup_and_exit(game);
	if (keycode == XK_W || keycode == XK_Up)
		move_on(&game->exec.play);
	if (keycode == XK_A)
		move_left(&game->exec.play);
	if (keycode == XK_D)
		move_right(&game->exec.play);
	if(keycode == XK_S || keycoe == XK_Down)
		move_back(&game->exec.play);
	if(keycode == XK_Left)
		turn_left(&game->exec.play);
	if(keycode == XK_Right)
		turn_right(&game->exec.play);
	return (SUCCESS);
}


}
void	listen(t_game *game)
{
	mlx_key_hook(game->win, tap_key, game);
	mlx_hook(game->win, 17, 1L << 17, w_close, game);
}

/*
#include <stdlib.h>for EXIT_SUCCESS, EXIT_FAILURE
#include <X11/keysym.h> key symbols for portable key handle

static int	w_close(t_fractal *fr)
{
	cleanup(fr, EXIT_SUCCESS);
	return (0);
}

static int	tap_key(int keycode, t_fractal *fr)
{
	if (XK_Escape == keycode)
		w_close(fr);
	else if (XK_equal == keycode || XK_plus == keycode || XK_KP_Add == keycode)
		fr->iterations += 10;
	else if (XK_KP_Subtract == keycode || XK_minus == keycode)
		fr->iterations -= 10;
	else if (XK_Left == keycode)
		fr->shift_x -= 0.5 * fr->zoom;
	else if (XK_Right == keycode)
		fr->shift_x += 0.5 * fr->zoom;
	else if (XK_Up == keycode)
		fr->shift_y += 0.5 * fr->zoom;
	else if (XK_Down == keycode)
		fr->shift_y -= 0.5 * fr->zoom;
	my_draw(fr);
	return (0);
}

static int	klick(int button, int x, int y, t_fractal *fr)
{
	if (button == 4)
		fr->zoom *= 0.85;
	else if (button == 5)
		fr->zoom *= 1.25;
	my_draw(fr);
	return (0);
}

void	listen(t_fractal *fr)
{
	mlx_key_hook(fr->win, tap_key, fr);
	mlx_mouse_hook(fr->win, klick, fr);
	mlx_hook(fr->win, 17, 1L << 17, w_close, fr);
	return ;
}

/*calls calc for each pixel in image
void	my_draw(t_fractal *fr)
{
	int		y;
	t_map	map;

	y = -1;
	map.scale_x = fr->zoom * 4 / (WIDTH -1);
	map.shift_x = fr->zoom * (-2) + fr->shift_x;
	map.scale_y = fr->zoom * (-4) / (HEIGHT -1);
	map.shift_y = fr->zoom * 2 + fr->shift_y;
	map.scale_i = (BLACK - WHITE) / fr->iterations;
	while (++y < HEIGHT)
		fractal_calc(y, fr, map);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img.img, 0, 0);
	return ;
}
*/
