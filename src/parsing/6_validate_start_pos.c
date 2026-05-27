/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_validate_start_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:20:02 by asato             #+#    #+#             */
/*   Updated: 2026/05/27 20:43:26 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"

static void	store_start_orientation(t_map *map)
{
	char	*dirs;
	int		i;

	dirs = "NSEW";
	i = 0;
	while (i < 4)
	{
		if (map->grid[map->start_pos.row][map->start_pos.col] == dirs[i])
		{
			map->start_orientaion = dirs[i];
			break ;
		}
		i++;
	}
}

int	get_max_width(t_map *map)
{
	int	i;
	int	line_len;
	int	temp_len;

	i = 0;
	line_len = 0;
	while (map->grid[i])
	{
		temp_len = ft_strlen(map->grid[i]);
		if (temp_len > line_len)
			line_len = temp_len;
		i++;
	}
	return (line_len);
}

static t_pos	find_start_pos(t_map *map)
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
		{
			if (map->grid[row_idx][col_idx] != '0'
				&& map->grid[row_idx][col_idx] != '1'
				&& map->grid[row_idx][col_idx] != ' ')
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

static int	count_char_in_map(t_map *map, char c)
{
	int	row_idx;
	int	col_idx;
	int	count;

	row_idx = 0;
	col_idx = 0;
	count = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (map->grid[row_idx][col_idx] != '\0')
		{
			if (map->grid[row_idx][col_idx] == c)
				count++;
			col_idx++;
		}
		row_idx++;
	}
	return (count);
}

// Check if a map has only either of N, S, E, W
int	validate_start_position(t_map *map)
{
	char	*dirs;
	int		found;
	int		result;
	int		i;

	dirs = "NSEW";
	found = 0;
	i = 0;
	while (i < 4)
	{
		result = count_char_in_map(map, dirs[i]);
		if (result > 1)
			return (0);
		if (result == 1)
			found++;
		i++;
	}
	if (found != 1)
		return (0);
	map->start_pos = find_start_pos(map);
	if (map->start_pos.row == -1 || map->start_pos.col == -1)
		return (0);
	map->width = get_max_width(map);
	store_start_orientation(map);
	return (1);
}
