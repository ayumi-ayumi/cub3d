/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:27:49 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 16:39:36 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
		return (c);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;

	c = 0;
	while (c <= 255) 
	{
		printf("Char %c (%d), ft: %d, org: %d\n",c,c,ft_isalnum(c),isalnum(c));
		c++;
	}
	return (0);
}//*/
