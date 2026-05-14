/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:21:37 by asato             #+#    #+#             */
/*   Updated: 2025/10/25 10:58:03 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (0);
}

/*
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	i++;
	return (i);
}
*/

void	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*joined_str;
	size_t			s1_len;
	size_t			s2_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = malloc(s1_len + s2_len + 1);
	if (!joined_str)
		return (free(s1), NULL);
	ft_memcpy(joined_str, s1, s1_len);
	ft_memcpy(joined_str + s1_len, s2, s2_len);
	joined_str[s1_len + s2_len] = '\0';
	free(s1);
	return (joined_str);
}
