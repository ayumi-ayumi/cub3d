/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:04 by chagen            #+#    #+#             */
/*   Updated: 2025/05/20 19:33:49 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while ((src[i] != '\0') && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*src[6] = {"Hello",
			"World",
			"Hello World!",
			"",
			"930v++=-\"",
			"0123456789ABCDEFG"};
	char		dst1[10];
	char		dst2[10];
	size_t		i;
	
	memset(dst1, 'c', 10);
	memset(dst2, 'c', 10);
	i = 0;
	while (i < 6)
	{
		printf("%zu \t %zu\t",ft_strlcpy(dst1,src[i],
10),strlcpy(dst2,src[i],10));
		printf("%s\t%s\n", dst1,dst2);
		i++;
	}
	return (1);
}//*/
