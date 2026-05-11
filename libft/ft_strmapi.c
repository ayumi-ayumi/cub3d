/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:08:57 by chagen            #+#    #+#             */
/*   Updated: 2025/05/28 14:21:50 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL || s[0] == '\0')
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
char	fu(unsigned int i, char c)
{
	if (i == 0)
		return ((char)c);
	else
		return ((char)ft_toupper((int)c));
}
void	test_strmapi(void)
{
	const char *test_str1 = "Hello World";
	const char *test_str4 = "";
	const char *expected1 = "HELLO WORLD";
	const char *expected4 = "";
	char *result1 = ft_strmapi((char const *)test_str1, &fu);
	char *result4 = ft_strmapi((char const *)test_str4, &fu);
	int	err;

	err = 0;
	printf("\n••••• START\tstrmapi\t\tTEST •••••\n");
	if (result1)
	{
		if (memcmp(result1, expected1, strlen(expected1) + 1) != 0)
		{
			printf("ERROR for \"%s\" (ex: %s)\n", result1, expected1);
			err++;
		}
		free(result1);
	}
	if (result4)
	{
		if (memcmp(result4, expected1, strlen(expected4) + 1) != 0)
		{
			printf("ERROR for \"%s\" (ex: %s)\n", result4, expected4);
			err++;
		}
		free(result4);
	}
	printf("ENDED\tstrmapi\tTEST with \t\t %d \t ERRORS\n", err);
}

int	main(void)
{
	test_strmapi();
	return (0);
}//*/