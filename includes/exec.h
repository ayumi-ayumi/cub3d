#ifndef EXEC_H
# define EXEC_H

# define SCREEN_HEIGHT 480
# define SCREEN_WIDTH 640
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
# define MOVESPEED 0.02125
# define ROTSPEED 0.015
# define MINI 10
# define TILE_SIZE 10
# define WALL_COLOR 0x333333
# define FLOOR_COLOR 0xCCCCCC
# define PLAYER_COLOR 0xFF0000
# define FAN_COLOR 0xDDFFCC

# include "cub3d.h"

/*structs*/
typedef struct s_paint
{
	t_pos			screen;
	t_pos			tex;
	double			percent;
	unsigned int	color;
}	t_paint;

typedef struct s_tile
{
	int				x;
	int				y;
	int				width;
	int				height;
	unsigned int	color;
}	t_tile;

/* mlx */
int			init_mlx(t_game *game);
void		free_mlx(t_game *game);
void		free_win(t_game *game);
void		free_mlx_texture(void *mlx, void **target);
// void		free_entire_mlx(t_game *game, t_exec *exec);

/* mlx Loop */
int			start_graphics(t_game *game);
int			key_hook(int keycode, void *param);
void		draw_minimap(t_game *game);
int			render_tile(t_game *game, t_tile tile);

void			img_pix_put(t_data *img, int x, int y, unsigned int color);
unsigned int	get_pixel_colour(t_data *img, int x, int y);


/*execution*/
int			init_play_data(t_game *game, t_exec *exec);
int			draw(t_game *game, t_move *move, t_data *screen);

/*raycast*/
int			raycast(t_game *game, t_exec *exec);
void		calc_start_values(t_play *play, double cam_x);
int			timing(t_move *move);
void		draw_mini_map(t_map *map, t_play *play, t_data *screen);

/*rendering*/
void		draw_line(t_exec *exec, int x);
void		put_pixel(t_data *img, int x, int y, int colour);
void		put_wall(t_exec *exec, t_paint *paint);

/*utils*/
t_vec		turn_vec(t_vec vec, double angle);
t_vec		add_vec(t_vec a, t_vec b);
t_vec		subst_vec(t_vec a, t_vec b);
t_vec		mult_vec(double factor, t_vec b);
t_vec		divt_vec(t_vec a, double dev);
#endif
