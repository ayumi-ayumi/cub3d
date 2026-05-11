/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:55:27 by chagen            #+#    #+#             */
/*   Updated: 2025/05/14 13:20:32 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int		main(void)
{
	char	*test1 = malloc(13);
	char	*org1 = malloc(13);
	size_t	i;

	i = 0;
	memset(test1, 'X',12);
	memset(org1, 'X', 12);
	while (i < 13)
	{
		printf("before: ft: %c, org: %c\n", test1[i], org1[i]);
		i++;
	}
	i = 0;
	printf("\n");
	memset(org1, 'o', 10);
	ft_memset(test1, 'o', 10);
	while (i < 13)
	{
		printf("after: ft: %c, org: %c\n", test1[i], org1[i]);
		i++;
	}
	printf("\n");
	free(test1);
	free(org1);
	return (0);
}//*/
