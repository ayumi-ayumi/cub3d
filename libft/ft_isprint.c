/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:57:46 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 17:10:46 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (c);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	int	c;

	c = 0;
	while (c <= 255) 
	{
		printf("Char %c (%d), ft: %d, org: %d\n",c,c,ft_isprint(c),isprint(c));
		c++;
	}
	return (0);
}//*/
