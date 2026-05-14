/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:21:56 by asato             #+#    #+#             */
/*   Updated: 2026/05/13 19:52:33 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_and_exit(char *error)
{
	printf("Error\n");
	printf("%s", error);
	exit(0);
}

void	error(char *error)
{
	printf("Error\n");
	printf("%s", error);
}
