/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:43 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:41:33 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	error_and_exit(char *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(0);
}

void	print_error(char *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
}
