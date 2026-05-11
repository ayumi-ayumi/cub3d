/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:09:51 by chagen            #+#    #+#             */
/*   Updated: 2025/06/03 17:42:22 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t n_memb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	if ((size != 0 && n_memb != 0 && n_memb > 2147483647 / size))
		return (NULL);
	arr = malloc(size * n_memb);
	if (n_memb == 0 || size == 0)
		return ((void *)arr);
	if (!arr)
		return (NULL);
	while (i < n_memb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
/*
#include <string.h>
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	size_t	m;
	size_t	s;
	int		err;
	char	*ft;
	char	*org;
	
	m = 50;
	s = 50;
	err = 0;
	printf("Int max> %d" ,INT_MAX);
	while (m < INT_MAX)
	{
		while(s < INT_MAX)
		{
			ft = (char *)ft_calloc(m,s);
			org = (char *)calloc(m,s);
			if (memcmp(ft,org,(s*m) + 1) != 0)
			{
				printf("ERROR for calloc(%zu,%zu)",m,s);
				err++;
			}
			printf("(%c)\n",org[0]);
			free(ft);
			free(org);
			s = s + 10000500;
		}
		m = m + 10000500;
	}
	printf("DONE WITH FT-MALLOC TEST \t FOUND %d MISTAKES\n", err);
	return (0);
}//*/
