/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:59:13 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 13:17:16 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int		main(void)
{
	const char	*test[6] = {
		"Hello World!",
		"",
		"12345",
		"cp -sKK@/0 iesl",
		"Test with spaces",
		NULL
	};
	int	i = 0;
	
	while (test[i] != NULL)
		{
			printf("\"%s\" is %zu (ft), %zu (org)\n", test[i], 
				ft_strlen(test[i]), strlen(test[i]));
			i++;
		}
	return (0);
}//*/
