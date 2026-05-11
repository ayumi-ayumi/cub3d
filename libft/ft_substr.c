/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:31:12 by chagen            #+#    #+#             */
/*   Updated: 2025/05/22 17:31:15 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)(ft_strlen(s)) <= start)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
		return (sub);
	}
	if ((ft_strlen(s)- start) < len)
		len = ft_strlen(s) - start;
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub [i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>
// Function to test substr
static void test_substr(void)
{
	char *words[5] = {
		"no spaces at start? and end?  \n  ",
		"012345no s",
		"0123456789abcdefghijklmnopqrstuvwxyz",
		" everything should stay the same set set set same ",
		"verylongs"
		};
	char *ex[5] = {
		"aces at",
		"5no s",
		"56789ab",
		"ything ",
		"ongs"
		};
	int i = 0;
	char *result;
	int	err = 0;

	printf("\n••••• START\tsubstr\t\tTEST •••••\n");
	while (i < 5)
	{
		result = ft_substr(words[i], 5, 7);
		if (!result)
		{
			continue;
			i++;
		}
		if (memcmp(result,ex[i],strlen(ex[i])) != 0)
		{
			printf("ERROR for \"%s\" (%s)\n",result, ex[i]);
			err++;
		}
		free(result);
		i++;
	}
	printf("DONE TESTING SUBSTR with\t %d\tERRORS\n", err);
}

int	main(void)
{
	printf("Can I print Dollars? one $ two $$ three $$$ for $$$$\n");
	test_substr();
	return (0);
}//*/