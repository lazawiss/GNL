/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:14:55 by lzannis           #+#    #+#             */
/*   Updated: 2025/01/20 11:49:52 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *s1, char *s2)
{
	char	*check;

	check = ft_strjoin(s1, s2);
	free(s1);
	return (check);
}

char	*ft_read_and_stock(int fd, char *bucket)
{
	int		read_n;
	char	*buffer;

	read_n = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_n > 0)
	{
		read_n = read(fd, buffer, BUFFER_SIZE);
		if (read_n == -1)
		{
			free(buffer);
			buffer = 0;
			return (NULL);
		}
		buffer[read_n] = '\0';
		bucket = free_join(bucket, buffer);
		if (!bucket)
			return (NULL);
		if (ft_strchr(bucket, '\n') == 1)
			break ;
	}
	free(buffer);
	return (bucket);
}

char	*ft_line(char *line_clean)
{
	int		i;
	char	c;
	int		start;
	int		len;

	i = 0;
	c = '\n';
	if (!line_clean[0])
		return (NULL);
	start = 0;
	while (line_clean[i])
	{
		if (((char *)line_clean)[i] == (char)c)
			break ;
		i++;
	}
	len = i + 1;
	line_clean = ft_substr((char *)line_clean, start, len);
	if (!line_clean)
	{
		free ((char *)line_clean);
		return (NULL);
	}
	line_clean[len] = '\0';
	return (line_clean);
}

char	*get_the_rest(char *bucket)
{
	int		i;
	char	c;
	int		start;
	int		len;
	char	*rest;

	i = 0;
	c = '\n';
	if (!bucket[0])
		return (0);
	len = ft_strlen(bucket);
	while (bucket[i])
	{
		if (((char *)bucket)[i] == (char)c)
			break ;
		i++;
	}
	start = i + 1;
	rest = ft_substr((char *)bucket, start, len);
	if (!rest)
		return (free ((char *)bucket), NULL);
	free(bucket);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*bucket = 0;	
	char		*line;
	char		*select_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(bucket);
		bucket = 0;
		return (NULL);
	}
	if (!bucket)
		bucket = ft_calloc((1 + 1), sizeof(char));
	if (!bucket)
		return (NULL);
	select_line = ft_read_and_stock(fd, bucket);
	if (!select_line)
		return (NULL);
	line = ft_line(select_line);
	bucket = get_the_rest(select_line);
	if (!bucket)
		return (free(select_line), select_line = 0, NULL);
	return (line);
}
/* int	main(void)
{
	int	fd;
	char	*str;
	int	i;

	fd = open("test", O_RDONLY);
	i = 0;
	while ((str = get_next_line(fd)))
	{
		printf("[%d]: %s", i++,str);
		free(str);
	}
	//get_next_line(-1); si i < 1
	close(fd);
	return (0);
} */
