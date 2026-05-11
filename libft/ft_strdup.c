/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:26:46 by chagen            #+#    #+#             */
/*   Updated: 2026/02/14 17:11:46 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int	main(void)
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
{
	char	*words[10];
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	words = {"Hello World",
			"1234567&",
			"",
			"the last string was empty",
			"with special characters ä, ö, ü"
			"Hello\0World",
			"last string was Hello World"
			"This is a very long string that might
				cause memory allocation FAILURE",
			"no 9",
			"last but not least"}
	while (j < 10)
	{
		if (memcmp(ft_strdup(words[j]),strdup(words[j]), sizeof(words[j])) != 0)
		{
			printf("ERROR word: %s", words[j]);
			i++;
		}
		j++;
	}
	printf("DONE WITH FT-STRDP TEST \t FOUND %d MISTAKES\n", i);
	return (0);
}//*/
