/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:43:17 by asato             #+#    #+#             */
/*   Updated: 2026/05/11 17:25:01 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H


# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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

size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);

void	free_map(t_cub *map);
void	free_mlx_img(t_vars *game, void **target);
void	free_mlx(t_vars *game);
void	cleanup_and_exit(t_vars *game);

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

#endif
