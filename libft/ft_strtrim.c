/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:34:31 by chagen            #+#    #+#             */
/*   Updated: 2025/05/23 15:34:33 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	ft_find(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if ((char)(set[i]) == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_jump_fo(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_find((char const)s1[i], set) && s1[i] != '\0')
	{
		if (!s1[i])
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_jump_ba(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_find((char const)s1[i], set))
	{
		if (!s1[i])
			break ;
		i--;
	}
	if (i == 0 && ft_find((char const)s1[i], set))
		return (0);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	size_t		start;
	size_t		end;
	char		*copy;

	if (!s1 || !set)
		return (NULL);
	start = ft_jump_fo(s1, set);
	end = ft_jump_ba(s1, set);
	if (end < start || s1[start] == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	copy = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		copy[i] = s1[start + i];
		i++;
	}
	return (copy);
}
/*
#include <stdio.h>
// Function to test strtrim
void test_strtrim(void)
{
	char *words[5] = {
		" \t  no spaces at start? and end?  \n  ",
		"$\%$\%$$$no special characters?$\%$$$\%$\%",
		"nothing there?",
		" everything should stay the same set set set same ",
		"               "
	};
	char *sts[5] = {"\t\n ", "$\%", "", "set", " "};
	char *ex[5] = {
		"no spaces at start? and end?",
		"no special characters?",
		"nothing there?",
		" everything should stay the same set set set same ",
		"\0"
	};
	char *temp;
	int err = 0;
	int i = 0;

	printf("\n••••• START\tstrtrim\t\tTEST •••••\n");
	printf("START strtrim TEST\n");
	while (i < 5)
	{
		temp = ft_strtrim(words[i], sts[i]);
		if (ft_memcmp(ex[i], temp, ft_strlen(temp)) != 0)
		{
			printf("ERROR for \t\"%s\"\t(%s)\n",temp, ex[i]);
			err++;
		}
		free(temp);
		i++;
	}
	printf("ENDED strtrim TEST with \t %d \t ERRORS.\n", err);
}

int	main(void)
{
	test_strtrim();
	return (0);
}//*/
