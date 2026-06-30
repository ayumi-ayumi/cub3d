/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:13:46 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 19:34:47 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

char	*get_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*temp;
	char	*joined;

	if (!stash)
		stash = ft_strdup("");
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), free(stash), stash = NULL, NULL);
		else if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		joined = ft_strjoin(stash, temp);
		free(stash);
		stash = joined;
	}
	free(temp);
	return (stash);
}

char	*extract_one_line(char *stash)
{
	char	*one_line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	one_line = malloc((i + 1) * sizeof(char));
	if (!one_line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		one_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		one_line[i++] = '\n';
	one_line[i] = '\0';
	return (one_line);
}

char	*remove_one_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1 * sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = get_stash(fd, stash);
	if (!stash)
		return (free(stash), NULL);
	line = extract_one_line(stash);
	stash = remove_one_line(stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
