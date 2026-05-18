/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:20:02 by asato             #+#    #+#             */
/*   Updated: 2026/05/17 19:31:39 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

// int	is_rectangular(t_cub *map)
// {
// 	int	first_row;
// 	int	row_idx;

// 	if (!map || !map->grid || map->height <= 0)
// 		return (0);
// 	first_row = get_row_length(map, 0);
// 	row_idx = 1;
// 	while (row_idx < map->height)
// 	{
// 		if (first_row != get_row_length(map, row_idx))
// 			return (0);
// 		row_idx++;
// 	}
// 	map->width = first_row;
// 	if (map->width < 5 || map->height < 4)
// 		return (0);
// 	if (map->height > map->width)
// 		return (0);
// 	return (1);
// }


int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

int	has_left_side_wall(t_cub *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] == ' ')
			col_idx++;
		if (map->grid[row_idx][col_idx] != '\n'
			&& map->grid[row_idx][col_idx] != '1')
			return (0);
		row_idx++;
	}
	return (1);
}
int	has_right_side_wall(t_cub *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] != '\n')
			col_idx++;
		if (map->grid[row_idx][col_idx - 1] != '1')
			return (0);
		row_idx++;
	}
	return (1);
}

int	has_this_row_wall(t_cub *map, int row_idx)
{
	int	col_idx;

	col_idx = 0;
	while (map->grid[row_idx][col_idx] != '\n')
	{
		if (map->grid[row_idx][col_idx] != '1')
			return (0);
		col_idx++;
	}
	return (1);
}

int	friend_with_0(char c)
{
	return (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}
int	check_around_0(t_cub *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 1;
	while (row_idx < map->height -1)
	{
		col_idx = 1;
		while (map->grid[row_idx][col_idx + 1] != '\n')
		{
			if (map->grid[row_idx][col_idx] == '0')
			{
				if (!friend_with_0(map->grid[row_idx - 1][col_idx]) //UP
				|| !friend_with_0(map->grid[row_idx][col_idx + 1]) // RIGHT
				|| !friend_with_0(map->grid[row_idx + 1][col_idx]) // DOWN
				|| !friend_with_0(map->grid[row_idx][col_idx - 1])) //LEFT
					return (0);
			}
			col_idx++;
		}
		row_idx++;
	}
	return (1);
}

int	is_enclosed_by_walls(t_cub *map)
{
	if (!has_this_row_wall(map, 0) || !has_this_row_wall(map, map->height - 1))
		return (0);
	if (!has_left_side_wall(map) || !has_right_side_wall(map))
		return (0);
	if (!check_around_0(map))
		return (0);
	return (1);
}
// Check if a map has only either of N, S, E, W
int	validate_start_position(t_cub *map)
{
	char	*dirs;
	int		flag;
	int		result;
	int		i;

	dirs = "NSEW";
	flag = 0;
	i = 0;
	while (i < 4)
	{
		result = count_char_in_map(map, dirs[i]);
		if (result > 1)
			return (0);
		if (result == 1)
			flag++;
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}
// Check if a map has only 1, 0, N, S, E, W or SPACE
int	validate_map_charset(t_cub *map)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] != '\n')
		{
			if (!is_allowed_char(map->grid[row_idx][col_idx]))
				return (0);
			col_idx++;
		}
		row_idx++;
	}
	return (1);
}
