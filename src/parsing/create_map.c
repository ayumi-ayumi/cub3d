/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:28:40 by asato             #+#    #+#             */
/*   Updated: 2026/05/16 17:44:38 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	create_grid(t_cub *map)
{
	int		fd;

	fd = open(map->map_path, O_RDONLY);
	if (fd == -1)
	{
		error("Failed opening a file or a file doesn't exit.\n");
		close(fd);
		return (0);
	}
	if (!read_map_from_file(fd, map))
		return (0);
	if (!map->grid)
		return (0);
	return (get_next_line(-1), close(fd), 1);
}

int	get_max_width(t_cub *map)
{
	int	i;
	int	line_len;
	int	temp_len;

	i = 0;
	while (i < map->height)
	{
		temp_len = ft_strlen(map->grid[i]);
		if (temp_len > line_len)
			line_len = temp_len;
		i++;
	}
	return (line_len - 1); // minus '\n'
}

int	read_map_from_file(int fd, t_cub *map)
{
	char	*line_buf;
	char	**new_grid;

	line_buf = get_next_line(fd);
	while (line_buf != NULL)
	{
		new_grid = append_row_to_grid(map->grid, line_buf, map->height);
		if (!new_grid)
		{
			if (line_buf)
				free(line_buf);
			get_next_line(-1);
			close(fd);
			free_map(map);
			return (0);
		}
		map->grid = new_grid;
		map->height++;
		line_buf = get_next_line(fd);
	}
	map->width = get_max_width(map);
	return (1);
}

char	**append_row_to_grid(char **grid, char *new_line, int current_size)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(*new_grid) * (current_size + 2));
	if (!new_grid)
		return (free(new_line), NULL);
	i = 0;
	while (i < current_size)
	{
		new_grid[i] = grid[i];
		i++;
	}
	new_grid[current_size] = new_line;
	new_grid[current_size + 1] = NULL;
	if (grid)
		free(grid);
	return (new_grid);
}
