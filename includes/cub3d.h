/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:43:17 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 16:39:59 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# include <stddef.h>/*for NULL*/

typedef int			t_bool;
typedef enum s_direction
{
	DIR_NO = 0,
	DIR_SO,
	DIR_WE,
	DIR_EA
}					t_direction;

/* STRUCTS */
typedef struct s_position
{
	int				row;
	int				col;
}					t_pos;

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct s_play
{
	t_vec			pos;
	t_vec			dir;
	t_vec			plane;
	t_vec			ray;
	t_pos			map;
	t_vec			delta_dist;
	t_vec			side_dist;
	t_pos			step;
	t_bool			wall_hit;
	t_direction		side;
	double			perp_wall_dist;
	int				texture_col;
}					t_play;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_data;

/*mlx img for walls*/
typedef struct s_exec
{
	t_data			*wall_texture;
	t_data			scre;
	int				draw_start;
	int				draw_end;
	unsigned int	ceiling;
	unsigned int	floor;
	unsigned int	wall_height;
	t_play			play;
}					t_exec;

typedef struct s_map
{
	char			**grid;
	int				height;
	int				width;
	char			start_orientation;
	t_pos			start_pos;
}					t_map;

/*paths to wall image files*/
typedef struct s_config
{
	char			**texture_paths;
	int				floor[3];
	int				ceiling[3];
}					t_config;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			*file_path;
	char			**file_contents;
	t_config		config;
	t_map			map;
	t_exec			exec;
	t_data			minimap;
}					t_game;

/* Error Handling */
void				error_and_exit(char *error);

/* Clean Up */
void				free_map(t_map *map);
void				free_string_array(char **arr);;
void				cleanup_and_exit(t_game *game);
void				print_error(char *error);

/* mlx clean up*/
void				free_mlx_texture(void *mlx, void **target);
void				free_mlx(t_game *game);
void				free_win(t_game *game);
void				free_entire_mlx(t_game *game);

#endif
