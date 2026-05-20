/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:26:46 by asato             #+#    #+#             */
/*   Updated: 2026/05/20 18:03:52 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>

int	flood_fill(t_game *game, int *collectible, int *exit)
{
	t_map	*copy;
	t_pos		*next;
	int			row;
	int			col;

	copy = game->copy;
	if (is_explorable(copy->start_pos.row, copy->start_pos.col, copy))
		push_stack(copy->start_pos, copy, game->dfs_stack);
	while (game->dfs_stack->top != -1
		&& *collectible <= copy->counts.collectibles)
	{
		next = pop_stack(game->dfs_stack);
		if (next == NULL)
			return (0);
		row = next->row;
		col = next->col;
		if (copy->grid[row][col] == 'C')
			(*collectible)++;
		if (copy->grid[row][col] == 'E')
			*exit = 1;
		copy->grid[row][col] = 'x';
		is_explorable_all_dir(row, col, copy, game);
	}
	return (0);
}
