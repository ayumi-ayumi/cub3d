/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:43:17 by asato             #+#    #+#             */
/*   Updated: 2026/05/16 13:37:00 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

/* STRUCTS */
typedef struct s_position
{
	int	row;
	int	col;
}				t_pos;

typedef struct s_texture
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
	void	*wall;
	void	*floor;
	int		width;
	int		height;
}				t_texture;

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
	t_texture	texture;
}				t_game;

int		execution(t_game *game);
#endif
