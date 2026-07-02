/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:43 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 16:23:16 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void	error_and_exit(char *error)
{
	printf("Error: %s\n", error);
	exit(0);
}

void	print_error(char *error)
{
	printf("Error: %s\n", error);
}
