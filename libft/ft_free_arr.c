/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:23:18 by chagen            #+#    #+#             */
/*   Updated: 2026/02/20 14:54:01 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_arr(char ***nullwords)
{
	size_t	i;

	i = 0;
	if (!nullwords || !*nullwords)
		return ;
	while ((*nullwords)[i] != NULL)
	{
		ft_free((void **)(&((*nullwords)[i])));
		i++;
	}
	free(*nullwords);
	*nullwords = NULL;
}
