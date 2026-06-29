/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ayumi <Ayumi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:43 by asato             #+#    #+#             */
/*   Updated: 2026/06/29 09:25:25 by Ayumi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void	error_and_exit(char *error)
{
	printf("Error: %s\n", error);
	exit(0);
}

void	print_error(char *error) // it can be stored in global utils
{
	printf("Error: %s\n", error);
}
