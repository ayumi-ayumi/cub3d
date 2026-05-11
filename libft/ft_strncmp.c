/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:07:08 by chagen            #+#    #+#             */
/*   Updated: 2025/05/19 17:41:17 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	size_t		n;
	const char	*s1;
	const char	*s2;

	s1 = "mode Soft Hard • Solo Duo Triosp set→9[Low";
	s2 = "mode Soft Hard • Solo Duo Triosp set→8[Low";
	n = 0;
	printf("execute test:\n");
	while (n < 70)
	{
		printf("n = %zu\t",n);
		printf("%d \t%d",ft_strncmp(s1,s2,n),strncmp(s1,s2,n));
		printf("\t%c  %c\n",s1[n-1],s2[n-1]);
		n++;
	}
	return (0);
}//*/
