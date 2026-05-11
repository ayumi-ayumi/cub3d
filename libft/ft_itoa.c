/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:48:49 by chagen            #+#    #+#             */
/*   Updated: 2025/05/28 12:10:44 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_charnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n = (n / 10);
		i++;
	}
	return (i + 1);
}

static char	*ft_intmin(void)
{
	char	*str;

	str = (ft_strdup("-2147483648"));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_intmin());
	len = ft_charnbr(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	str[--len] = n + '0';
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int		i[4] = {-2147483648, 0, 10, 2147483647};
	char	*ex[4] = {"-2147483648", "0", "10", "2147483647"};
	int		j;
	int		err;
	
	j = 0;
	err = 0;
	while (j < 4)
	{
		if (memcmp(ft_itoa(i[j]),ex[j],strlen(ex[j])) != 0)
		{
			err++;
			printf("ERROR FOR number
			: %d \t\tstring: %s\n\n",i[j], ft_itoa(i[j]));
		}
		j++;
	}
	printf("ENDED\titoa\tTEST with \t%d\tERRORS\n",err);
	return (0);
}//*/
