/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:25:01 by chagen            #+#    #+#             */
/*   Updated: 2025/05/23 13:25:04 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	j;
	unsigned int	i;
	char			*new;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new [i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

/*
int	main(void)
{	
	char		*words1;
	char		*words2;
	char const	*s1;
	char const	*s2;
	int			i;
	int			j;
	int			nulls;
	char		*result;

	words1 = "mit Ümlaut 1#@ *\\/ and now a nullterm";
	words2 = "one two three for five six seven 8 9 10 \0 11 12 13";
	printf("START strjoin TEST with teststring:\n%s\n%s\n\n",words1,words2);
	i = 0;
	nulls = 0;
	while (words1[i])
	{
		s1 =  (char const *)(words1 + i);
		j = 0;
		while (words2[j])
		{
			s2 = (char const *)(words2 + j);
			result = ft_strjoin(s1,s2);
			if (result == NULL || !result)
				nulls++;
			else
			{
				printf("i = %d, j = %d\t%s\n",i,j,result);
				free(result);
			}
			j = j + 13;
		}
		i = i + 13;
		printf(" - - -\n");
	}
	printf("DONE TESTING strjoin with\t %d\tNULL POINTERS\n",i);
	return (0);
}//*/