/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:33:13 by chagen            #+#    #+#             */
/*   Updated: 2025/05/20 19:10:06 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	s_len;
	size_t	j;

	j = 0;
	len = 0;
	s_len = 0;
	while (dst[len] != '\0' && len < size)
		len++;
	while (src[s_len])
		s_len++;
	if (size == 0 || len == size)
		return (len + s_len);
	while (src[j] != '\0' && len + j < size - 1)
	{
		dst[len + j] = src[j];
		j++;
	}
	dst[len + j] = '\0';
	return (len + s_len);
}

/*
#include <stdio.h>
#include <bsd/string.h>
#include<stdlib.h>

void	test(char *start,const char *src, size_t size)
{
	char buffer1[size];
    char buffer2[size];

	strncpy(buffer1,start,size);
	buffer1[size-1] = '\0';
	strncpy(buffer2,start,size);
	buffer2[size-1] = '\0';
	ft_strlcat(buffer1,src,size);
	strlcat(buffer2,src,size);
	buffer2[size-1] = '\0';
	if (strncmp(buffer1,buffer2,size))
	{
		printf("\nFALSE strings differe for size %zu", size);
		printf("\t%s\t%s",buffer1,buffer2);
		return;
	}
	printf("\nFINE for size %zu\tSource: %s\tDestinations:\t%s\t%s",
		size,src,buffer1,buffer2);
	return;
}

int	main(void)
{	int				i;
	int				j;
	size_t			s;
	const char		*src;
	char			*dst;
	const char *srcwords[] = {"erstes Wort", "Ümlaut", "1#@ *\\/"};
    char dstwords[3][50] = {"erstes Wort", "Ümlaut", "1#@ *\\/"};

	i = -1;
	while (i++ < 2)
	{
		j = -1;
		src = (const char *)srcwords[i];
		while (j++ < 2)
		{
			s = 5;
			dst = dstwords[j];
			printf("\n\nsrc  %s\tdst  %s\ti %d\tj %d\n",src,dst,i,j);
			while (s++ < 18)
				test(dst,src,s);
		}
	}
	return (0);
}//*/
