/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_load_map_and_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:45:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/27 20:01:18 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>

int	load_map_and_config(t_game *game)
{
	t_map	*map;

	game->map = (t_map){NULL, 0, 0, 0, {-1, -1}};
	map = &game->map;
	if (!parse_file(game) || !validate_map(map))
		return (0);
	return (1);
}

// For testing
// void	print_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		printf("line %i: %s\n", i, map[i]);
// 		i++;
// 	}
// }
