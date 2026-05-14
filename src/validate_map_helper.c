/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:20:02 by asato             #+#    #+#             */
/*   Updated: 2026/05/14 18:44:16 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	has_top_bottom_walls(t_cub *map)
{
	int	col_idx;

	col_idx = 0;
	while (col_idx < map->width)
	{
		if (map->grid[0][col_idx] != '1'
			|| map->grid[map->height - 1][col_idx] != '1')
			return (0);
		col_idx++;
	}
	return (1);
}

int	has_sides_walls(t_cub *map)
{
	int	row_idx;

	row_idx = 0;
	while (row_idx < map->height)
	{
		if (map->grid[row_idx][0] != '1'
			|| map->grid[row_idx][map->width - 1] != '1')
			return (0);
		row_idx++;
	}
	return (1);
}

int	is_enclosed_by_walls(t_cub *map)
{
	if (!has_top_bottom_walls(map) || !has_sides_walls(map))
		return (0);
	return (1);
}

int	validate_map_char_counts(t_cub *map)
{
	char	*dirs;
	int		flag;
	int		result;
	int		i;

	if (!map || !map->grid)
		return (0);
	dirs = "NSEW";
	flag = 0;
	i = 0;
	while (i < 4)
	{
		result = 0;
		if ((result = count_char_in_map(map, dirs[i])) > 1)
			return (0);
		if (result == 1)
			flag++;
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}
