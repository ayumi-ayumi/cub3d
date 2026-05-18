/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:41:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/16 13:28:39 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	get_row_length(t_cub *map, int row_idx)
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

int	count_char_in_map(t_cub *map, char c)
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

t_pos	find_pos(t_cub *map, char target)
{
	int		row_idx;
	int		col_idx;
	t_pos	target_pos;

	target_pos = (t_pos){-1, -1};
	row_idx = 0;
	while (row_idx < map->height)
	{
		col_idx = 0;
		while (col_idx < map->width)
		{
			if (map->grid[row_idx][col_idx] == target)
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

t_cub	copy_map(t_cub *map)
{
	t_cub	copy;

	if (!map || map->height <= 0)
		return ((t_cub){0});
	copy = (t_cub){0};
	copy.grid = malloc(sizeof(char *) * (map->height + 1));
	if (!copy.grid)
		return (copy);
	dup_grid(map, &copy);
	copy.grid[map->height] = NULL;
	copy.width = map->width;
	copy.height = map->height;
	copy.size = map->width * map->height;
	copy.counts = map->counts;
	copy.exit_pos = map->exit_pos;
	copy.start_pos = map->start_pos;
	return (copy);
}

t_cub	dup_grid(t_cub *map, t_cub *copy)
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
