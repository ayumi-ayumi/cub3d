/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:02:16 by asato             #+#    #+#             */
/*   Updated: 2025/07/23 16:52:54 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

/* ***libft*** */
// char	*ft_strchr(char *s, char c);
// size_t	ft_strlen(char *s);
// void	*ft_memcpy(char *dest, char *src, size_t n);
// char	*ft_strjoin(char *s1, char *s2);

/* ***Main function*** */
char	*get_next_line(int fd);

#endif
