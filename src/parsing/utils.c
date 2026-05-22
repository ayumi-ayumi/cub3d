/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:41:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/20 18:27:14 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	get_row_length(t_map *map, int row_idx)
{
	int	len;

	len = 0;
	if (!map || !map->grid || !map->grid[row_idx])
		return (0);
	len = ft_strlen(map->grid[row_idx]);
	if (len && map->grid[row_idx][len - 1] == '\n')
		len--;
	return (len);
}

int	count_char_in_map(t_map *map, char c)
{
	int	row_idx;
	int	col_idx;
	int	count;

	// if (!map || !map->grid)
	// 	return (0);
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
		while (map->grid[row_idx][col_idx] != '\n')
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

t_map	copy_map(t_map *map)
{
	t_map	copy;

	if (!map || map->height <= 0)
		return ((t_map){0});
	copy = (t_map){0};
	copy.grid = malloc(sizeof(char *) * (map->height + 1));
	if (!copy.grid)
		return (copy);
	dup_grid(map, &copy);
	copy.grid[map->height] = NULL;
	copy.width = map->width;
	copy.height = map->height;
	copy.size = map->width * map->height;
	// copy.counts = map->counts;
	// copy.exit_pos = map->exit_pos;
	copy.start_pos = map->start_pos;
	return (copy);
}

t_map	dup_grid(t_map *map, t_map *copy)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		copy->grid[i] = ft_strdup(map->grid[i]);
		if (!copy->grid[i])
		{
			while (--i >= 0)
				free(copy->grid[i]);
			free(copy->grid);
			copy->grid = NULL;
			return (*copy);
		}
		i++;
	}
	return (*copy);
}
