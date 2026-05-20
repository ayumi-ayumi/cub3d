/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/20 18:28:17 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>

int	init_map(t_game *game)
{
	t_map	*map;
	t_map	*copy;

	map = game->map;
	copy = game->copy;
	if (!map || !copy)
		return (0);
	if (!read_file(game) || !validate_map(map))
	// if (!read_file(game) || !validate_map(map) || !validate_elements(map))
		return (0);
	map->size = map->height * map->width;
	*copy = copy_map(map);
	copy->start_pos = find_start_pos(copy);
	printf("row: %i, col: %i\n", copy->start_pos.row, copy->start_pos.col);
	if (copy->start_pos.row == -1 || copy->start_pos.col == -1)
		return (0);
	map->start_pos = copy->start_pos;
	// if (!check_collectibles_reachability(game))
	// 	return (0);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!map || !map->grid)
		return (error("No map found.\n"), 0);
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
