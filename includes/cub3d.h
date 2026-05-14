/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:43:17 by asato             #+#    #+#             */
/*   Updated: 2026/05/13 19:56:10 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"


/* MACROS */
# define IMG_PLAYER_UP		"./textures/player_up.xpm"
# define IMG_PLAYER_RIGHT	"./textures/player_right.xpm"
# define IMG_PLAYER_DOWN	"./textures/player_down.xpm"
# define IMG_PLAYER_LEFT	"./textures/player_left.xpm"
# define IMG_EXIT			"./textures/exit.xpm"
# define IMG_EXIT_OPEN		"./textures/exit_open.xpm"
# define IMG_COLLECTIVE		"./textures/collectible.xpm"
# define IMG_FLOOR			"./textures/floor.xpm"
# define IMG_WALL			"./textures/wall.xpm"

/* ENUMS */
typedef enum s_direction
{
	DIR_UP = 1,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT
}			t_direction;

typedef enum s_keycode
{
	ARROW_UP = 65362,
	ARROW_RIGHT = 65363,
	ARROW_DOWN = 65364,
	ARROW_LEFT = 65361,
	KEY_W = 119,
	KEY_D = 100,
	KEY_S = 115,
	KEY_A = 97,
	KEY_ESC = 65307
}			t_keycode;

/* STRUCTS */
typedef struct s_position
{
	int	row;
	int	col;
}				t_pos;

typedef struct s_obj_counts
{
	int	collectibles;
	int	exit;
	int	player;
}				t_obj_counts;

typedef struct s_cub
{
	char			*map_path;
	char			**grid;
	int				height;
	int				width;
	int				size;
	t_obj_counts	counts;
	t_pos			exit_pos;
	t_pos			start_pos;
}				t_cub;

typedef struct s_img
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*exit_open;
	int		width;
	int		height;
}				t_img;

typedef struct s_stack
{
	int		top;
	t_pos	*data;
}				t_stack;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_cub	*map;
	t_cub	*copy;
	int			moves;
	t_img		img;
	t_stack		*dfs_stack;
}				t_vars;

int	create_grid(t_cub *map);
int	read_map_from_file(int fd, t_cub *map);
char	**append_row_to_grid(char **grid, char *new_line, int current_size);
int	init_map(t_vars *game);
int	validate_map(t_cub *map);
void	count_map_objects(t_cub *map);
int	check_collectibles_reachability(t_vars *game);
int	get_row_length(t_cub *map, int row_idx);
int	count_char_in_map(t_cub *map, char c);
t_pos	find_pos(t_cub *map, char target);
t_cub	copy_map(t_cub *map);
t_cub	dup_grid(t_cub *map, t_cub *copy);
int	is_rectangular(t_cub *map);
int	has_top_bottom_walls(t_cub *map);
int	has_sides_walls(t_cub *map);
int	is_enclosed_by_walls(t_cub *map);
int	validate_map_char_counts(t_cub *map);

void	error_and_exit(char *error);
void	error(char *error);

int	flood_fill(t_vars *game, int *collectible, int *exit);


void	init_stack(t_stack *dfs_stack, t_cub *map);
void	push_stack(t_pos input_pos, t_cub *copy, t_stack *dfs_stack);
t_pos	*pop_stack(t_stack *dfs_stack);
int	is_explorable(int row, int col, t_cub *map);
void	is_explorable_all_dir(int row, int col, t_cub *copy, t_vars *game);

void	free_map(t_cub *map);
void	free_mlx_img(t_vars *game, void **target);
void	free_mlx(t_vars *game);
void	cleanup_and_exit(t_vars *game);

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

#endif
