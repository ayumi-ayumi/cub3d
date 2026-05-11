/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:55:38 by chagen            #+#    #+#             */
/*   Updated: 2026/03/13 19:45:47 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char *dst, char const *src, size_t *index)
{
	size_t	len;

	len = ft_strlen(src);
	ft_memcpy(dst + *index, src, len);
	*index += len;
}

char	*ft_strjoinjoin(char const *s1, char const *s2, char const *s3)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	new = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	ft_copy(new, s1, &i);
	ft_copy(new, s2, &i);
	ft_copy(new, s3, &i);
	new[i] = '\0';
	return (new);
}
