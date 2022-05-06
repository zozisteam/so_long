/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:38:43 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 21:14:30 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (c == 0)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *)str);
		str++;
	}
	return (0);
}

size_t	ft_strlen(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src && src[i] != '\0')
		i++;
	return ((unsigned)i);
}

char	*ft_strdup(char *src)
{
	char	*x;
	int		i;

	i = 0;
	x = (char *)malloc(ft_strlen(src) + 1);
	if (!x)
		return (NULL);
	while (src[i] != '\0')
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}
