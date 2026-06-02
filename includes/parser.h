/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:02:52 by asato             #+#    #+#             */
/*   Updated: 2026/06/02 18:17:45 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "cub3d.h"
#include <stdio.h>






/* Load map and config */
int	load_map_and_config(t_game *game);
int	parse_file(t_game *game);

/* Extract elements */
int	exract_elements(t_game *game);
int	extract_map(t_game *game);

/* validate a map*/
int	validate_map(t_map *map);
int	validate_start_position(t_map *map);
int	is_enclosed_by_walls(t_map *map);

/* Error Handling */
void	error_and_exit(char *error);
void	print_error(char *error);

/* Clean Up */
void	free_string_array(char **arr);

#endif
