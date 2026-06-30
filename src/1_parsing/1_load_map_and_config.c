/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_load_map_and_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 18:47:13 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	load_map_and_config(t_game *game)
{
	t_map	*map;

	if (!game)
		return (0);
	game->map = (t_map){
		.grid = NULL,
		.height = 0,
		.width = 0,
		.start_orientation = 0,
		.start_pos = {-1, -1}
	};
	map = &game->map;
	if (!parse_file(game) || !validate_map(map))
		return (0);
	return (1);
}
