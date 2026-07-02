/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:02:52 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 16:27:57 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "cub3d.h"

/* Load map and config */
int		load_map_and_config(t_game *game);
int		parse_file(t_game *game);

/* Extract elements */
int		extract_elements(t_game *game);
int		extract_map(t_game *game);
int		extract_texture_config(t_game *game);
int		extract_rgb_config(t_game *game);
void	free_texture_paths(char **texture_paths_arr);

/* validate a map*/
int		validate_map(t_map *map);
int		validate_start_position(t_map *map);
int		is_enclosed_by_walls(t_map *map);
int		check_around_0(t_map *map);
int		has_left_side_wall(t_map *map);
int		has_right_side_wall(t_map *map);
int		has_this_row_wall(t_map *map, int row_idx);

#endif
