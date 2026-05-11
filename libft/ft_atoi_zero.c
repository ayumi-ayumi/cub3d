/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:29:19 by chagen            #+#    #+#             */
/*   Updated: 2025/10/20 12:23:47 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*this atoi does not wrap around - instead it returns 0*/

static int	ft_check_max(unsigned int num, int neg, char c, char nc)
{
	unsigned int	new;

	new = (unsigned int)c - '0';
	if (num == (((unsigned int)INT_MAX - new + 1) / 10) && neg == -1
		&& nc == '\0')
		return (INT_MIN);
	else
		return (0);
}

int	ft_atoi_zero(const char *nptr)
{
	int		i;
	int		neg;
	int		num;

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
		if (num > ((INT_MAX - (nptr[i] - '0')) / 10))
			return (ft_check_max((unsigned int)num, neg, nptr[i], nptr[i + 1]));
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}

/*
int	main(void)
{
	printf("-2147483646: %li\n", (long)ft_atoi_zero("-2147483646"));
	printf("-2147483647: %li\n", (long)ft_atoi_zero("-2147483647"));
	printf("INT_MIN: -2147483648: %li\n", (long)ft_atoi_zero("-2147483648"));
	printf("-2147483649: %li\n", (long)ft_atoi_zero("-2147483649"));
	printf("-2147483650: %li\n", (long)ft_atoi_zero("-2147483650"));
	printf("-2147483651: %li\n", (long)ft_atoi_zero("-2147483651"));
	printf("-21474836480: %li\n", (long)ft_atoi_zero("-21474836480"));
	printf("-21474836481: %li\n", (long)ft_atoi_zero("-21474836481"));
	printf("-21474836482: %li\n", (long)ft_atoi_zero("-21474836482"));
	printf("2147483646: %li\n", (long)ft_atoi_zero("2147483646"));
	printf("INT_MAX: 2147483647: %li\n", (long)ft_atoi_zero("2147483647"));
	printf("2147483648: %li\n", (long)ft_atoi_zero("2147483648"));
	printf("2147483649: %li\n", (long)ft_atoi_zero("2147483649"));
	printf("2147483650: %li\n", (long)ft_atoi_zero("2147483650"));
	printf("2147483651: %li\n", (long)ft_atoi_zero("2147483651"));
	return (0);
}
//*/
