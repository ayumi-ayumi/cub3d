/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:55:30 by chagen            #+#    #+#             */
/*   Updated: 2025/05/20 18:50:03 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*this atoi does wrap around */

static int	ft_check_max(int num, char c, int neg)
{
	if (num == ((INT_MAX - 7) / 10) && neg == -1 && c == '8')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
	{
		neg = -neg;
		i++;
	}
	if (nptr[i] == '+' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		i++;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (ft_check_max(num, nptr[i], neg))
			return (INT_MIN);
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}

/*
int	main(void)
{
	printf("-2: %li\n", (long)ft_atoi("-2"));
	printf("-214748363: %li\n", (long)ft_atoi("-214748363"));
	printf("-2147483639: %li\n", (long)ft_atoi("-2147483639"));
	printf("-2147483640: %li\n", (long)ft_atoi("-2147483640"));
	printf("-2147483645: %li\n", (long)ft_atoi("-2147483645"));
	printf("-2147483646: %li\n", (long)ft_atoi("-2147483646"));
	printf("-2147483647: %li\n", (long)ft_atoi("-2147483647"));
	printf("-2147483648: %li\n", (long)ft_atoi("-2147483648"));
	printf("-2147483649: %li\n", (long)ft_atoi("-2147483649"));
	printf("-2147483650: %li\n", (long)ft_atoi("-2147483650"));
	printf("-2147483651: %li\n", (long)ft_atoi("-2147483651"));
	printf("2147483647: %li\n", (long)ft_atoi("2147483647"));
	printf("2147483648: %li\n", (long)ft_atoi("2147483648"));
	printf("2147483649: %li\n", (long)ft_atoi("2147483649"));
	printf("2147483650: %li\n", (long)ft_atoi("2147483650"));
	printf("2147483651: %li\n", (long)ft_atoi("2147483651"));
	return (0);
}
//*/
