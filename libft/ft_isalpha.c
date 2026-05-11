/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:35:32 by chagen            #+#    #+#             */
/*   Updated: 2025/05/12 17:13:40 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
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
	char	b;

	c = 0;
	b = 0;
	while (c <= 255) 
	{
		printf("Char %c (%d), ft: %d, org: %d\n",b,c,ft_isalpha(c),isalpha(c));
		c++;
		b++;
	}
	return (0);
}//*/
