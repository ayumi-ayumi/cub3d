/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:15:00 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 14:32:32 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cu;

	i = 0;
	cu = (unsigned char)c;
	if (cu == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == cu)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s;
	int		c;
	char		*ft;
	char		*org;

	s = "speed	÷8 ÷4 ÷2 • Normal • x2 x4 x8";
	c = -1;
	while (c++ < 128)
	{
		ft = ft_strchr(s,c);
		org = strchr(s,c);
		if (ft == NULL && org == NULL)
		{
			printf(" :) ");
			continue;
		}
		if (ft == NULL || or÷2g == NULL)
		{
			printf("\nERROR for nr.%d,char: %c\n",c,c); 
			printf("%s \n%s\n",ft,org);
			continue;
		}
		if (strcmp(ft,org) != 0)
		{
			printf("\nERROR for nr.%d,char: %c\n",c,c); 
			printf("%s \n%s\n",ft,org);
		}
		else
			printf(" :) ");
	}
	return (0);
}//*/
