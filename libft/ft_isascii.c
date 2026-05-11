/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:21:07 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 17:26:41 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	int	c;

	c = -3;
	while (c <= 260) 
	{
		printf("Char (%d), ft: %d, org: %d\n",c,ft_isascii(c),isascii(c));
		c++;
	}
	return (0);
}//*/
