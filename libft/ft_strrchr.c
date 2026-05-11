/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:57 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 17:04:48 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
		i++;
	if (uc == '\0')
		return ((char *)&s[i]);
	i = i - 1;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == uc)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (0);
}
/*
#include <string.h>
int	main(void)
{
	const char	*s;
	int		c;
	char		*ft;
	char		*org;

	s = "speed	÷8 ÷4 ÷2 • Normal • x2 x4 x8";
	c = -1;
	while (c++ < 129)
	{
		ft = ft_strrchr(s,c);
		org = strrchr(s,c);
		if (ft == NULL && org == NULL)
		{
			printf(" :) ");
			continue;
		}
		if (ft == NULL || org == NULL)
		{
			printf("\nNULL ERROR for nr.%d,char: %c\n",c,c); 
			printf("f\t%s \no\t%s\n",ft,org);
			continue;
		}
		if (strcmp(ft,org) != 0)
		{
			printf("\nString ERROR for nr.%d,char: %c\n",c,c); 
			printf("%s \n%s\n",ft,org);
		}
		if (ft != org) 
		{
            		printf("\nPointer ERROR for nr.%d, char: %c\n", c, c);
            		printf("ft: %p \norg: %p\n", (void *)ft, (void *)org);
		}
		if (ft == org)
			printf("FINE %d",c);
		else
			printf("nothing happend for char %c nr. %d  ",c,c);
	}
	return (0);
}//*/
