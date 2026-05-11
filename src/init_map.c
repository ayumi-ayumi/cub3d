/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2025/11/21 21:04:46 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map(t_vars *game)
{
	t_so_long	*map;
	t_so_long	*copy;

	map = game->map;
	copy = game->copy;
	if (!map || !copy)
		return (0);
	if (!create_grid(map) || !validate_map(map))
		return (0);
	count_map_objects(map);
	map->size = map->height * map->width;
	*copy = copy_map(map);
	copy->start_pos = find_pos(copy, 'P');
	copy->exit_pos = find_pos(copy, 'E');
	if (copy->start_pos.row == -1 || copy->start_pos.col == -1
		|| copy->exit_pos.row == -1 || copy->exit_pos.col == -1)
		return (0);
	map->start_pos = copy->start_pos;
	map->exit_pos = copy->exit_pos;
	if (!check_collectibles_reachability(game))
		return (0);
	return (1);
}

int	validate_map(t_so_long *map)
{
	if (!map || !map->grid)
		return (error("No map found.\n"), 0);
	if (!is_rectangular(map))
		return (error("Map is not rectangular.\n"), 0);
	if (!is_enclosed_by_walls(map))
		return (error("Map is not surrounded by walls🧱.\n"), 0);
	if (!validate_map_char_counts(map))
	{
		error("The map must have only one exit and player, and collectives.\n");
		return (0);
	}
	return (1);
}

void	count_map_objects(t_so_long *map)
{
	map->counts.collectibles = count_char_in_map(map, 'C');
	map->counts.exit = count_char_in_map(map, 'E');
	map->counts.player = count_char_in_map(map, 'P');
}

int	check_collectibles_reachability(t_vars *game)
{
	int	found_collectible;
	int	found_exit;

	if (!game || !game->map || !game->copy || ! game->dfs_stack)
		return (0);
	found_collectible = 0;
	found_exit = 0;
	init_stack(game->dfs_stack, game->copy);
	flood_fill(game, &found_collectible, &found_exit);
	if (game->map->counts.collectibles != found_collectible || found_exit != 1)
		return (0);
	return (1);
}
