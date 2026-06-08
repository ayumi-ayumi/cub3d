/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_validate_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:20:02 by asato             #+#    #+#             */
/*   Updated: 2026/06/07 14:51:38 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"

static int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

// Check if a map has only 1, 0, N, S, E, W or SPACE
static int	validate_map_charset(t_map *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] != '\0')
		{
			if (!is_allowed_char(map->grid[row_idx][col_idx]))
				return (0);
			col_idx++;
		}
		row_idx++;
	}
	return (1);
}

static void	replace_start_pos_char_0(t_map *map)
{
	int	row;
	int	col;

	row = map->start_pos.row;
	col = map->start_pos.col;
	map->grid[map->start_pos.row][map->start_pos.col] = '0';
}



int	validate_map(t_map *map)
{
	if (!map || !map->grid)
		return (print_error("No map found.\n"), 0);
	if (!validate_map_charset(map))
	{
		print_error("The map contains invalid characters.\n");
		return (0);
	}
	if (!validate_start_position(map))
	{
		print_error("The map must have only one start position.\n");
		return (0);
	}
	if (!is_enclosed_by_walls(map))
		return (print_error("Map is not surrounded by walls🧱 or invalid\n"), 0);
	replace_start_pos_char_0(map);
	return (1);
}
