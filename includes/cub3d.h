/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:43:17 by asato             #+#    #+#             */
/*   Updated: 2026/06/02 17:36:17 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
//# include "exec.h"

typedef enum s_direction
{
	DIR_NO = 0,
	DIR_SO,
	DIR_WE,
	DIR_EA
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
	int		row;
	int		col;
}			t_pos;

/*paths to wall image files*/
typedef struct s_config
{
	char	**dir_path;
	// char	*no;
	// char	*so;
	// char	*we;
	// char	*ea;
	int		floor[3];
	int		ceiling[3];
}			t_config;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	char		start_orientation;
	t_pos		start_pos;
}				t_map;

typedef struct s_exec
{
	void	**dir_texture;
	// void	*no;
	// void	*so;
	// void	*we;
	// void	*ea;
}			t_exec;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*file_path;
	char		**file_contents;
	t_config	config;
	t_map		map;
	t_exec		exec;
}				t_game;

int		execution(t_game *game);

/* Clean Up */
void	free_map(t_map *map);
void	free_entire_mlx(t_game *game);
void	cleanup_and_exit(t_game *game);
#endif
