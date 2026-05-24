/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:22:02 by asato             #+#    #+#             */
/*   Updated: 2026/05/24 18:07:20 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	open_file(t_game *game)
{
	int	fd;

	fd = open(game->file_path, O_RDONLY);
	if (fd == -1)
	{
		error("Failed opening a file or a file doesn't exit.\n");
		close(fd);
		return (0);
	}
	if (!read_file(fd, game)) // Read a file and store the contents to game->file_contents
		return (0);
	if (!exract_elements(game)) // Extract config fron game->file_contents
		return (0);
	printf("height: %i\n", game->map.height);

	return (close(fd), 1);
}

char	*extract_path(char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

int	extract_color_rgb(int rgb[3], char *str)
{
	int		i;
	char	*temp;
	char	**rgb_str;
	int		num;

	i = 2;
	while (str[i] == ' ')
		i++;
	temp = &str[i];
	rgb_str = ft_split(temp, ',');
	i = 0;
	while (rgb_str[i])
	{
		if (i >= 3)
			return (0);
		num = 0;
		num = ft_atoi(rgb_str[i]);
		if (num < 0 || num > 255)
			return (0);
		rgb[i] = num;
		i++;
	}
	return (1);
}

int	store_map_grid(t_game *game, char *line, int i)
{
	// game->map.grid = malloc(sizeof(game->map.grid) * (game->map.height + 1));
	// if (!game->map.grid)
	// 	return (0);
	game->map.grid[i] = ft_strdup(line);
	if (!game->map.grid[i])
		return (0);
	// while (i < game->map.height )
	// {
	// 	map_grid[i] = ft_strdup(line);
	// 	if (!map_grid[i])
	// 		return (0);
	// 	i++;
	// }
	// map_grid[i] = NULL;
	// game->map.grid = map_grid;
	return (1);
}

int	exract_elements(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 6)
	// while (game->file_contents[i] != NULL)
	{
		if (ft_strncmp(game->file_contents[i], "NO", 2) == 0)
		{
			game->config.no = extract_path(game->file_contents[i]);
			flag++;
		}
		if (ft_strncmp(game->file_contents[i], "SO", 2) == 0)
		{
			game->config.so = extract_path(game->file_contents[i]);
			flag++;
		}
		if (ft_strncmp(game->file_contents[i], "WE", 2) == 0)
		{
			game->config.we = extract_path(game->file_contents[i]);
			flag++;
		}
		if (ft_strncmp(game->file_contents[i], "EA", 2) == 0)
		{
			game->config.ea = extract_path(game->file_contents[i]);
			flag++;
		}
		if (ft_strncmp(game->file_contents[i], "F", 1) == 0)
		{
			if (!extract_color_rgb(game->config.floor, game->file_contents[i]))
				return (0);
			flag++;
		}
		if (ft_strncmp(game->file_contents[i], "C", 1) == 0)
		{
			if (!extract_color_rgb(game->config.ceiling, game->file_contents[i]))
				return (0);
			flag++;
		}
		i++;
	}
	game->map.height = game->map.height - i + 1;
	if (game->file_contents[i][0] == '1' || game->file_contents[i][0] == ' ')
	{
		game->map.grid = malloc(sizeof(game->map.grid) * (game->map.height + 1));
		if (!game->map.grid)
			return (0);
		int line_num = 0;
		while (game->file_contents[i] != NULL)
		{
			if (!store_map_grid(game, game->file_contents[i], line_num))
				return (0);
			i++;
			line_num++;
		}
		game->map.grid[line_num] = NULL;
	}
	if (flag != 6)
		return (0);
	return (1);
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
	return (line_len - 1); // minus '\n'
}

void	count_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_contents[i])
		i++;
	game->map.height = i - 1;
}

int	read_file(int fd, t_game *game)
{
	char	*next_line;
	char	*contents_str;
	char	*temp;

	contents_str = ft_strdup("");
	if (!contents_str)
		return (0);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		temp = ft_strjoin(contents_str, next_line);
		free(contents_str);
		contents_str = temp;
		free(next_line);
		// game->map.height++;
	}
	game->file_contents = ft_split(contents_str, '\n');
	if (!game->file_contents)
		return (0);
	count_lines(game);
	free(contents_str);
	contents_str = NULL;
	return (1);
}


// char	**append_row_to_grid(char **file_contents, char *new_line, int cur_size)
// {
// 	char	**temp_contents;
// 	int		i;

// 	temp_contents = malloc(sizeof(*temp_contents) * (cur_size + 2));
// 	if (!temp_contents)
// 		return (free(new_line), NULL);
// 	i = 0;
// 	while (i < cur_size)
// 	{
// 		temp_contents[i] = file_contents[i];
// 		i++;
// 	}
// 	temp_contents[cur_size] = new_line;
// 	temp_contents[cur_size + 1] = NULL;
// 	if (file_contents)
// 		free(file_contents);
// 	return (temp_contents);
// }
// int	read_file(int fd, t_game *game)
// {
// 	char	*line_buf;
// 	char	**new_grid;

// 	line_buf = get_next_line(fd);
// 	while (line_buf != NULL)
// 	{
// 		printf("%s\n", line_buf);
// 		new_grid = append_row_to_grid(game->map->grid, line_buf, game->map->height);
// 		if (!new_grid)
// 		{
// 			if (line_buf)
// 				free(line_buf);
// 			get_next_line(-1);
// 			close(fd);
// 			free_map(game->map);
// 			return (0);
// 		}
// 		game->map->grid = new_grid;
// 		game->map->height++;
// 		line_buf = get_next_line(fd);
// 	}
// 	game->map->width = get_max_width(game->map);
// 	return (1);
// }

// char	**append_row_to_grid(char **grid, char *new_line, int current_size)
// {
// 	char	**new_grid;
// 	int		i;

// 	new_grid = malloc(sizeof(*new_grid) * (current_size + 2));
// 	if (!new_grid)
// 		return (free(new_line), NULL);
// 	i = 0;
// 	while (i < current_size)
// 	{
// 		new_grid[i] = grid[i];
// 		i++;
// 	}
// 	new_grid[current_size] = new_line;
// 	new_grid[current_size + 1] = NULL;
// 	if (grid)
// 		free(grid);
// 	return (new_grid);
// }
