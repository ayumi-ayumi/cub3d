/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_load_map_and_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/25 17:54:46 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>

t_pos	find_start_pos(t_map *map)
{
	int		row_idx;
	int		col_idx;
	t_pos	target_pos;

	target_pos = (t_pos){-1, -1};
	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] != '\0')
		// while (col_idx < map->width)
		{
			if (map->grid[row_idx][col_idx] != '0'
				|| map->grid[row_idx][col_idx] != '1'
				|| map->grid[row_idx][col_idx] != ' ')
			{
				target_pos.row = row_idx;
				target_pos.col = col_idx;
			}
			col_idx++;
		}
		row_idx++;
	}
	return (target_pos);
}

int	load_map_and_config(t_game *game)
{
	t_map	*map;

	game->map = (t_map){NULL, 0, 0, {-1, -1}};
	map = &game->map;
	if (!parse_file(game) || !validate_map(map))
		return (0);
	map->start_pos = find_start_pos(map);
	if (map->start_pos.row == -1 || map->start_pos.col == -1)
		return (0);
	map->width = get_max_width(map);
	return (1);
}

// For testing
// void	print_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		printf("line %i: %s\n", i, map[i]);
// 		i++;
// 	}
// }
