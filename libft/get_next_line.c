/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:20:49 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 21:14:11 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_get_line(char *lines)
{
	char	*line;
	int		i;

	i = 0;
	if (!lines[i])
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
	{
		line[i] = lines[i];
		i++;
	}
	if (lines[i] == '\n')
	{
		line[i] = lines[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_lines(char *lines)
{
	char	*updated_lines;
	int		i;
	int		j;

	i = 0;
	if (!lines)
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
	{
		free(lines);
		return (NULL);
	}
	updated_lines = (char *)malloc(sizeof(char) * (ft_strlen(lines) - i + 1));
	if (!updated_lines)
		return (NULL);
	i++;
	j = 0;
	while (lines[i])
		updated_lines[j++] = lines[i++];
	updated_lines[j] = '\0';
	free(lines);
	return (updated_lines);
}

char	*read_fd(int fd, char *lines)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(buff, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buff[read_bytes] = '\0';
		lines = ft_strjoin(lines, buff);
	}
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = read_fd(fd, lines);
	if (!lines)
	{	
		free(lines);
		return (NULL);
	}
	line = ft_get_line(lines);
	lines = ft_update_lines(lines);
	return (line);
}
