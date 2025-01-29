/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:26:02 by lzannis           #+#    #+#             */
/*   Updated: 2025/01/18 14:54:43 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	while (s[i])
	{
		if (((char *)s)[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cal;
	size_t	i;

	i = 0;
	cal = malloc(nmemb * size);
	if (!cal)
		return (NULL);
	while (i < (nmemb * size))
	{
		cal[i] = 0;
		i++;
	}
	return (cal);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc (sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2)) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(((char *)s)))
		len = 0;
	else if (len > (ft_strlen((char *)s) - start))
		len = ft_strlen((char *)s) - start;
	ptr = (char *)malloc ((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (j < len)
	{
		ptr[j] = s[start];
		j++;
		start++;
	}
	ptr[j] = '\0';
	return (ptr);
}
