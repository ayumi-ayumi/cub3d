/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:23:21 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 17:12:11 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
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
		printf("Char %c (%d), ft: %d, org: %d\n",c,c,ft_isdigit(c),isdigit(c));
		c++;
	}
	return (0);
}//*/
