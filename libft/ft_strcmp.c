/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:06:15 by chagen            #+#    #+#             */
/*   Updated: 2025/09/05 10:06:16 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (s1 || s2)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		i;
	int		ft;
	int		org;
	char	*arr[3];

	i = 0;
	arr[0] = "Hello";
	arr[1] = "World";
	arr[2] = NULL;
	while (arr[i])
	{
		ft = ft_strncmp(arr[i], arr[i]);
		org = strcmp(arr[i], arr[i]);
		if (ft != org)
			printf("ERROR! ft = %d, org = %d\n", ft, org);
		ft = ft_strncmp(arr[i] + 1, arr[i]);
		org = strcmp(arr[i] + 1, arr[i]);
		printf("ft = %d, org = %d\n ", ft, org);
		if (ft != org)
			printf("ERROR! ft = %d, org = %d\n", ft, org);
		i++;
	}
	printf("done - no errors\n");
	return (0);
}
*/
