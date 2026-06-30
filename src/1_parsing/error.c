/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:43 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 19:36:44 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void	error_and_exit(char *error)
{
	printf("Error: %s\n", error);
	exit(0);/*@Ayumi: i think we should exit with a FAIL = 1 here not with SUCCESS = 0 */
}

void	print_error(char *error) // it can be stored in global utils
{
	printf("Error: %s\n", error);
}
