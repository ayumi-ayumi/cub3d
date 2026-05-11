/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:56:23 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 12:00:59 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	i;

	i = 38;
	while(i++ < 100)
		printf("%d  %c\t%c\t%c\n",i,i,ft_tolower(i), tolower(i));
	return (0);
}//*/
