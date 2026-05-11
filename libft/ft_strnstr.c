/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:48:56 by chagen            #+#    #+#             */
/*   Updated: 2025/05/20 15:42:08 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
// Function to test strnstr
void test_strnstr(void)
{
	char *words[5] = {
		" \t  no spaces at start? and end?  \n  ",
		"no special characters?$",
		"nothing there?",
		" everything should stay the same set set set same ",
		""
	};
	char *li_words[5] = {
			"\t ",
			"cha",
			"othin",
			"XXX",
			" this sh"};
	int		i = 0;
	char	*tempf;
	char	*tempo;
	int 	err = 0;

	printf("\n••••• START\tstrnstr\t\tTEST •••••\n");
	while (i < 5)
	{
		tempf = ft_strnstr((const char *)words[i],(const char*)li_words[i],20);
		tempo = strnstr((const char *)words[i],(const char *)li_words[i],20);
		if (!tempf && !tempo)
		{
			i++;
			continue;
		}
		if (!tempf || !tempo)
		{
			err++;
			i++;
			continue;
		}
		else if (memcmp(tempf,tempo,strlen(tempo)) != 0)
		{
			printf("ERROR \t\"%s\"\t(%s)\n",tempf, tempo);
			err++;
		}
		printf("FINE \t\"%s\"\t(%s)\n",tempf, tempo);
		i++;
	}
	printf("ENDED strnstr TEST with \t %d \t ERRORS.\n", err);
}

int	main(void)
{
	test_strnstr();
	return (0);
}//*/
