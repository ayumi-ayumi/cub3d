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
# include <stddef.h>/*for NULL*/

/* STRUCTS */
typedef struct s_position
{
	int		row;
	int		col;
}			t_pos;

/*paths to wall image files*/
typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
}			t_config;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	t_pos		start_pos;
	char		start_orientation;
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
}				t_game;

int		execution(t_game *game);
void	cleanup_exec(t_game *game, t_exec *exec);
#endif
