/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:09:53 by lzannis           #+#    #+#             */
/*   Updated: 2025/01/18 15:03:26 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
