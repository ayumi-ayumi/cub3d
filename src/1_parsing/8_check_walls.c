/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_check_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:15 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:25:10 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	friend_with_0(char c)
{
	return (c == '1' || c == '0'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_around_0(t_map *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 1;
	while (row_idx < map->height - 1)
	{
		col_idx = 1;
		while (map->grid[row_idx][col_idx + 1] != '\0')
		{
			if (map->grid[row_idx][col_idx] == '0')
			{
				if (!friend_with_0(map->grid[row_idx - 1][col_idx])
					|| !friend_with_0(map->grid[row_idx][col_idx + 1])
					|| !friend_with_0(map->grid[row_idx + 1][col_idx])
					|| !friend_with_0(map->grid[row_idx][col_idx - 1]))
					return (FAIL);
			}
			col_idx++;
		}
		row_idx++;
	}
	return (SUCCESS);
}

int	has_left_side_wall(t_map *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] == ' ')
			col_idx++;
		if (map->grid[row_idx][col_idx] != '\0'
			&& map->grid[row_idx][col_idx] != '1')
			return (FAIL);
		row_idx++;
	}
	return (SUCCESS);
}

int	has_right_side_wall(t_map *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx + 1] != '\0')
			col_idx++;
		if (map->grid[row_idx][col_idx] != '1')
			return (FAIL);
		row_idx++;
	}
	return (SUCCESS);
}

int	has_this_row_wall(t_map *map, int row_idx)
{
	int	col_idx;

	col_idx = 0;
	while (map->grid[row_idx][col_idx] != '\0')
	{
		while (map->grid[row_idx][col_idx] == ' ')
			col_idx++;
		if (map->grid[row_idx][col_idx] != '1')
			return (FAIL);
		col_idx++;
	}
	return (SUCCESS);
}
