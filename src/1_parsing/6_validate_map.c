/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_validate_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:28:05 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 20:05:57 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/* Check if a map has only 1, 0, N, S, E, W or SPACE */
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

int	is_enclosed_by_walls(t_map *map)
{
	if (!has_this_row_wall(map, 0) || !has_this_row_wall(map, map->height - 1))
		return (0);
	if (!has_left_side_wall(map) || !has_right_side_wall(map))
		return (0);
	if (!check_around_0(map))
		return (0);
	return (1);
}

static void	replace_start_pos_char_0(t_map *map)
{
	t_pos	start_pos;

	start_pos = map->start_pos;
	map->grid[start_pos.row][start_pos.col] = '0';
}

int	validate_map(t_map *map)
{
	if (!map || !map->grid)
		return (print_error("No map found"), 0);
	if (!validate_map_charset(map))
	{
		print_error("The map contains invalid characters");
		return (0);
	}
	if (!validate_start_position(map))
	{
		print_error("The map must have only one start position");
		return (0);
	}
	if (!is_enclosed_by_walls(map))
		return (print_error("Map is not surrounded by walls🧱 or invalid"), 0);
	replace_start_pos_char_0(map);
	return (1);
}
