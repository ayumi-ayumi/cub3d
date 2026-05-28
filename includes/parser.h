/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:02:52 by asato             #+#    #+#             */
/*   Updated: 2026/05/28 15:26:37 by asato            ###   ########.fr       */
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

# include "cub3d.h"

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


/* Load map and config */
int	load_map_and_config(t_game *game);
int	parse_file(t_game *game);

/* Extract elements */
int	exract_elements(t_game *game);
int	extract_map(t_game *game, int *i);

/* validate a map*/
int	validate_map(t_map *map);
int	validate_start_position(t_map *map);
int	is_enclosed_by_walls(t_map *map);

/* Error Handling */
void	error_and_exit(char *error);
void	print_error(char *error);

/* Clean Up */
void	free_string_array(char **arr);
void	free_map(t_map *map);
void	cleanup_and_exit(t_game *game);

#endif
