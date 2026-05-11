/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:35:05 by chagen            #+#    #+#             */
/*   Updated: 2025/05/14 15:27:42 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*z;
	const unsigned char	*q;

	i = 0;
	z = (unsigned char *)dest;
	q = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	else
	{
		while (i < n)
		{
			z[i] = q[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char    dest1[50] = "DestinationZielDestination";
    char    dest2[50] = "DestinationZielDestination";
    char    src1[50] = "123456789";
    char    src2[50] = "123456789";
	char	*ft;
	char	*org;

    printf("Before\n Src: %s, %s, Dest: %s, %s\n", src1, src2, dest1, dest2);
    memcpy(dest1, src1,5);
    ft_memcpy(dest2, src2,5);
    printf("After\nSrc: %s, %s, Dest: %s,%s\n", src1, src2, dest1, dest2);
	printf("overlapping mem: %s, %s\n", src1, src2);
	ft = (char *)ft_memcpy(src2 + 2,src2 + 5, 4);
	org = (char *)memcpy(src1 + 2,src1 + 5, 4);
	printf("overlapping: ft:%s, org: %s\n", ft, org);
    return (0);
}
//*/
