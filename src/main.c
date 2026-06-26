/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:40:38 by asato             #+#    #+#             */
/*   Updated: 2026/06/22 13:48:35 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>

static t_bool	is_extension_correct(t_game *game, char *file_name)
{
	int	file_name_len;

	if (!file_name)
		return (FALSE);
	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + (file_name_len - 4), ".cub", 4) != 0)
		return (FALSE);
	game->file_path = file_name;
	return (TRUE);
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
	if (execute_game(&game) == FAIL) // The function name can be execute_game()
		return (cleanup_and_exit(&game), FAIL);
	free_entire_mlx(&game);
	cleanup_and_exit(&game);
	return (0);
}
