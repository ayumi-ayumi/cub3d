/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:26:46 by asato             #+#    #+#             */
/*   Updated: 2026/05/13 19:54:27 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	init_stack(t_stack *dfs_stack, t_cub *map)
{
	int	i;

	i = 0;
	dfs_stack->top = -1;
	dfs_stack->data = malloc(sizeof(t_pos) * map->size);
	if (!dfs_stack->data)
	{
		perror("Failed malloc dfs_stack.data.\n");
		while (i < map->height)
			free(map->grid[i++]);
		free(map->grid);
	}
}

void	push_stack(t_pos input_pos, t_cub *copy, t_stack *dfs_stack)
{
	t_pos	pos;

	pos.row = input_pos.row;
	pos.col = input_pos.col;
	if (dfs_stack->top >= copy->size - 1)
		return (error("Stack is full!\n"));
	dfs_stack->data[dfs_stack->top + 1] = pos;
	dfs_stack->top = dfs_stack->top + 1;
}

t_pos	*pop_stack(t_stack *dfs_stack)
{
	t_pos	*pop_pos;

	if (dfs_stack->top == -1)
		return (error("Stack is empty!\n"), NULL);
	pop_pos = &(dfs_stack->data[dfs_stack->top]);
	dfs_stack->top = dfs_stack->top - 1;
	return (pop_pos);
}

int	is_explorable(int row, int col, t_cub *map)
{
	if (row < 0 || row >= map->height || col < 0 || col >= map->width)
		return (0);
	if (map->grid[row][col] == '1')
		return (0);
	if (map->grid[row][col] == 'x')
		return (0);
	return (1);
}

void	is_explorable_all_dir(int row, int col, t_cub *copy, t_vars *game)
{
	if (is_explorable(row - 1, col, copy))
		push_stack((t_pos){row - 1, col}, copy, game->dfs_stack);
	if (is_explorable(row + 1, col, copy))
		push_stack((t_pos){row + 1, col}, copy, game->dfs_stack);
	if (is_explorable(row, col + 1, copy))
		push_stack((t_pos){row, col + 1}, copy, game->dfs_stack);
	if (is_explorable(row, col - 1, copy))
		push_stack((t_pos){row, col - 1}, copy, game->dfs_stack);
}
