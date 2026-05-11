/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:17 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 11:53:19 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	i;

	i = 90;
	while(i++ < 130)
		printf("%d  %c\t%c\t%c\n",i,i,ft_toupper(i), toupper(i));
	return (0);
}//*/
