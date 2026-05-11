/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:05:14 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 19:15:31 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;
	unsigned char		uc;

	uc = (unsigned char)c;
	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == uc)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	void	*s1;
	const void	*s2;
	char	*cont;
	int	c;

	s1 = malloc(50);
	cont = "mode	Soft Hard • Solo Duo Trio";
	s2 = (const void *)memcpy(s1,cont,41);
	c = -1;
	while (c < 180)
	{	
		if (memchr(s2,c,40) == ft_memchr(s2,c,40))
			printf("fine for c = %c\n",c);
		else
			printf("ERROR for c = %c\tnr. %d\n",c,c);
		c++;
	}
	return (0);
}//*/
