/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:41:54 by asato             #+#    #+#             */
/*   Updated: 2026/05/27 20:12:46 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

// int	get_row_length(t_map *map, int row_idx)
// {
// 	int	len;

// 	len = 0;
// 	if (!map || !map->grid || !map->grid[row_idx])
// 		return (0);
// 	len = ft_strlen(map->grid[row_idx]);
// 	if (len && map->grid[row_idx][len - 1] == '\n')
// 		len--;
// 	return (len);
// }

int	get_max_width(t_map *map)
{
	int	i;
	int	line_len;
	int	temp_len;

	i = 0;
	line_len = 0;
	while (map->grid[i])
	{
		temp_len = ft_strlen(map->grid[i]);
		if (temp_len > line_len)
			line_len = temp_len;
		i++;
	}
	return (line_len); // minus '\n'
}
