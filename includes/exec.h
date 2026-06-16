#ifndef EXEC_H
# define EXEC_H

# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 600
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
# define NORTH_SOUTH 1
# define WEST_EAST 0

# include "cub3d.h"
#include <stdio.h>
/*mlx img for walls*/
// typedef struct s_exec
// {
// 	void	*no;
//  	void	*so;
//  	void	*we;
//  	void	*ea;
// }			t_exec;

/* mlx */
int			init_mlx(t_game *game);
void		free_mlx(t_game *game);
void		free_win(t_game *game);
void		free_mlx_texture(void *mlx, void **target);
// void		free_entire_mlx(t_game *game, t_exec *exec);

/* mlx Loop */
int	start_graphics(t_game *game);
int	key_hook(int keycode, void *param);
void	minimap(t_game *game);

/*execution*/
int			init_play_data(t_game *game, t_exec *exec);
t_vec		turn_vec(t_vec vec, double angle);
int			draw(t_game *game, t_move *move, t_data *screen);

/*raycast*/
int			raycast(t_game *game, t_exec *exec);
void		calc_start_values(t_play *play);
int			timing(t_move *move);

/*rendering*/
void		draw_line(t_exec *exec, int x);
void		put_pixel(t_data *img, int x, int y, int colour);
void		put_wall(t_exec *exec, int *i, int tex_x, int x);
#endif
