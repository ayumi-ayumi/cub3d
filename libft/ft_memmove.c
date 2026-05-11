/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:51:08 by chagen            #+#    #+#             */
/*   Updated: 2025/05/14 16:51:11 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ddest;
	const unsigned char	*ssrc;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest && dest < src + n)
	{
		i = n;
		while (i-- > 0)
			ddest[i] = ssrc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ddest[i] = ssrc[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_memmove(size_t i)
{
	char    dest1[50] = "Hello World";
    char    dest2[50] = "Hello World";
    char    src1[50] = "abcdefghijklmnopqrstuvwxyz";
    char    src2[50]= "abcdefghijklmnopqrstuvwxyz";

	printf("before:Src: %s, %s, Dest: %s, %s\n\n", src1, src2, dest1, dest2);
	memmove(dest1, src1,i);
	ft_memmove(dest2, src2,i);
	printf("after:\nSrc: %s, %s, Dest: %s, %s\n\n", src1, src2, dest1, dest2);
	printf("overlapping before: ft:%s, org: %s\n\n", src2, src1);
	ft_memmove(src2 + 5,src2 + 2, i);
	memmove(src1 + 5,src1 + 2, i);
	printf("overlapping after: ft:%s, org: %s\n\n", src2, src1);
	return;
}

int main(void)
{
	size_t	i;

	i = 0;
	while (i < 15)
	{
		printf("\n\ntest with n = %zu\n", i);
		test_memmove(i);
		i++;
	}
    return (0);
}//*/
