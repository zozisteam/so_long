/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:19:41 by zozi              #+#    #+#             */
/*   Updated: 2022/05/06 19:39:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (start > ft_strlen(s) || *s == '\0')
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = (char *) malloc(len + 1 * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
