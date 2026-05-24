/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:02:52 by asato             #+#    #+#             */
/*   Updated: 2026/05/24 16:49:16 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
	KEY_A = 97,
	KEY_D = 100,
	KEY_S = 115,
	KEY_W = 119,
	ARROW_LEFT = 65361,
	ARROW_UP = 65362,
	ARROW_RIGHT = 65363,
	ARROW_DOWN = 65364,
	KEY_ESC = 65307
}			t_keycode;

/* STRUCTS */
typedef struct s_position
{
	int	row;
	int	col;
}				t_pos;

// typedef struct s_obj_counts
// {
// 	int	collectibles;
// 	int	exit;
// 	int	player;
// }				t_obj_counts;

typedef struct s_img
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
	void	*wall;
	void	*floor;
	int		width;
	int		height;
}				t_img;

typedef struct s_stack
{
	int		top;
	t_pos	*data;
}				t_stack;

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
}				t_config;

typedef struct s_map
{
	char			**grid;
	int				height;
	int				width;
	int				size;
	t_pos			start_pos;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*file_path;
	char		**file_contents;
	t_config	config;
	t_map		map;
	t_map		copy;
	t_img		img;
}				t_game;

int	open_file(t_game *game);
int	read_map_from_file(int fd, t_game *game);
char	**append_row_to_grid(char **grid, char *new_line, int current_size);
int	init_map(t_game *game);
int	validate_map(t_map *map);
int	validate_elements(t_map *map);

void	count_map_objects(t_map *map);
int	check_collectibles_reachability(t_game *game);
int	get_row_length(t_map *map, int row_idx);
int	count_char_in_map(t_map *map, char c);
t_pos	find_start_pos(t_map *map);
t_map	copy_map(t_map *map);
t_map	dup_grid(t_map *map, t_map *copy);
// int	is_rectangular(t_map *map);
int	has_top_bottom_walls(t_map *map);
int	has_sides_walls(t_map *map);
int	is_enclosed_by_walls(t_map *map);
// int	validate_map_char_counts(t_map *map);
int	validate_start_position(t_map *map);
int	validate_map_charset(t_map *map);
int	read_file(int fd, t_game *game);
int	exract_elements(t_game *game);

void	error_and_exit(char *error);
void	error(char *error);

// int	flood_fill(t_game *game, int *collectible, int *exit);

void	init_stack(t_stack *dfs_stack, t_map *map);
void	push_stack(t_pos input_pos, t_map *copy, t_stack *dfs_stack);
t_pos	*pop_stack(t_stack *dfs_stack);
int	is_explorable(int row, int col, t_map *map);
void	is_explorable_all_dir(int row, int col, t_map *copy, t_game *game);

void	free_map(t_map *map);
void	free_mlx_img(t_game *game, void **target);
void	free_mlx(t_game *game);
void	cleanup_and_exit(t_game *game);

#endif
