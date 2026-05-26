/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:40:38 by asato             #+#    #+#             */
/*   Updated: 2026/05/20 18:22:26 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>

int	is_extension_correct(char *file_name)
{
	int	result;
	int	file_name_len;

	if (!file_name)
		return (0);
	file_name_len = ft_strlen(file_name);
	result = ft_strncmp(file_name + (file_name_len - 4), ".cub", 4);
	if (result == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_map		map;
	t_map		copy;
	// t_stack		dfs_stack;

	if (ac != 2)
		error_and_exit("No map file passed. Choose a map you want to play🎮.\n");
	if (!is_extension_correct(av[1]))
		error_and_exit("File extension must be \".cub\".\n");
	map = (t_map){NULL, 0, 0, 0, {-1, -1}};
	copy = (t_map){NULL, 0, 0, 0, {-1, -1}};
	// map = ft_calloc((t_map))
	// dfs_stack = (t_stack){-1, NULL};
	game = (t_game){.map = &map, .copy = &copy};
	game.file_path = ft_strdup(av[1]);
	if (!game.file_path)
		return (cleanup_and_exit(&game), 1);
	if (!init_map(&game))
		return (cleanup_and_exit(&game), 1);
	if (!execution(&game))
	// 	return (cleanup_and_exit(&game), 1);
	return (0);
}
