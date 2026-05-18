/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:40:38 by asato             #+#    #+#             */
/*   Updated: 2026/05/13 19:50:05 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
	t_vars		game;
	t_cub		map;
	t_cub		copy;
	t_stack		dfs_stack;

	if (ac != 2)
		error_and_exit("No map file passed. Choose a map you want to play🎮.\n");
	if (!is_extension_correct(av[1]))
		error_and_exit("File extension must be \".cub\".\n");
	map = (t_cub){NULL, NULL, 0, 0, 0, {0, 0, 0}, {-1, -1}, {-1, -1}};
	copy = (t_cub){NULL, NULL, 0, 0, 0, {0, 0, 0}, {-1, -1}, {-1, -1}};
	dfs_stack = (t_stack){-1, NULL};
	game = (t_vars){.map = &map, .copy = &copy, .dfs_stack = &dfs_stack};
	map.map_path = ft_strdup(av[1]);
	if (!map.map_path)
		return (cleanup_and_exit(&game), 1);
	if (!init_map(&game))
		return (cleanup_and_exit(&game), 1);
	// if (!init_mlx(&game))
	// 	return (cleanup_and_exit(&game), 1);
	return (0);
}
