/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/24 17:57:12 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>

int	init_map(t_game *game)
{
	t_map	*map;
	// t_map	*copy;

	map = &game->map;
	// copy = &game->copy;
	if (!map)
		return (0);
	if (!open_file(game) || !validate_map(map))
	// if (!open_file(game) || !validate_map(map) || !validate_elements(map))
		return (0);
	map->size = map->height * map->width;
	// *copy = copy_map(map);
	map->start_pos = find_start_pos(map);
	if (map->start_pos.row == -1 || map->start_pos.col == -1)
		return (0);
	return (1);
}

void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("line %i: %s\n", i, map[i]);
		i++;
	}
}

int	validate_map(t_map *map)
{
	if (!map || !map->grid)
		return (error("No map found.\n"), 0);
	print_map(map->grid);
	if (!validate_map_charset(map))
	{
		error("The map contains invalid characters.\n");
		return (0);
	}
	if (!validate_start_position(map))
	{
		error("The map must have only one start position.\n");
		return (0);
	}
	if (!is_enclosed_by_walls(map))
		return (error("Map is not surrounded by walls🧱.\n"), 0);
	return (1);
}

// int	validate_elements(t_map *map)
// {

// }

// int	check_collectibles_reachability(t_game *game)
// {
// 	int	found_collectible;
// 	int	found_exit;

// 	if (!game || !game->map || !game->copy || ! game->dfs_stack)
// 		return (0);
// 	found_collectible = 0;
// 	found_exit = 0;
// 	init_stack(game->dfs_stack, game->copy);
// 	flood_fill(game, &found_collectible, &found_exit);
// 	if (game->map->counts.collectibles != found_collectible || found_exit != 1)
// 		return (0);
// 	return (1);
// }
