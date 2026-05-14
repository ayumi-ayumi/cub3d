/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:02:16 by asato             #+#    #+#             */
/*   Updated: 2025/07/18 17:42:52 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ***libft*** */
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
void	*ft_memcpy(char *dest, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);

/* ***Main function*** */
char	*get_next_line(int fd);

#endif
