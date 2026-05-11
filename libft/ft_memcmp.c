/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:01:21 by chagen            #+#    #+#             */
/*   Updated: 2025/05/20 12:44:42 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*p1;
	const unsigned char		*p2;
	size_t					i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	void	*s1;
	void	*s2;
	char	*cont;
	size_t	i;

	s1 = malloc(50);
	s2 = malloc(50);
	cont = "mode	Soft Hard • Solo Duo Trio";
	memcpy(s1,cont,41);
	i = 0;
	printf("ft\torgi\n");
	while (i < 50)
	{	
		memcpy(s2,cont,i);
		printf("%d\t%d\n",ft_memcmp(s1,s2,40),memcmp(s1,s2,40));
		i++;
	}
	return (0);
}//*/
