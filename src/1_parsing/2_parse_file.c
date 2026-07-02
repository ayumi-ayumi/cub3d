/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:25:09 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:08:55 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parser.h"
#include <stdio.h>

static void	count_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_contents[i])
		i++;
	game->map.height = i - 1;
}

static int	read_file(int fd, t_game *game)
{
	char	*next_line;
	char	*contents_str;
	char	*temp;

	contents_str = ft_strdup("");
	if (!contents_str)
		return (perror("malloc"), FAIL);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		temp = ft_strjoin(contents_str, next_line);
		free(contents_str);
		contents_str = temp;
		free(next_line);
	}
	game->file_contents = ft_split(contents_str, '\n');
	if (!game->file_contents)
		return (perror("malloc"), FAIL);
	count_lines(game);
	ft_free((void **)&contents_str);
	return (SUCCESS);
}

int	parse_file(t_game *game)
{
	int	fd;

	fd = open(game->file_path, O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed opening a file or a file doesn't exit");
		close(fd);
		return (FAIL);
	}
	if (read_file(fd, game) == FAIL)
		return (FAIL);
	if (extract_elements(game) == FAIL)
		return (close(fd), free_string_array(game->file_contents), FAIL);
	free_string_array(game->file_contents);
	return (close(fd), SUCCESS);
}
