/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:40:38 by asato             #+#    #+#             */
/*   Updated: 2026/06/20 13:17:59 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>

static int	is_extension_correct(t_game *game, char *file_name)
{
	int	file_name_len;

	if (!file_name)
		return (0);
	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + (file_name_len - 4), ".cub", 4) != 0)
		return (0);
	game->file_path = file_name;
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		error_and_exit("No map file passed. Choose a map you want to play🎮.\n");
	if (!is_extension_correct(&game, av[1]))
		error_and_exit("File extension must be \".cub\".\n");
	if (!load_map_and_config(&game))
		return (cleanup_and_exit(&game), 1);
	if (execution(&game) == FAIL)
		return (cleanup_and_exit(&game), FAIL);
	free_entire_mlx(&game);
	cleanup_and_exit(&game);
	return (0);
}
