/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:03:38 by alalmazr          #+#    #+#             */
/*   Updated: 2021/12/03 14:44:51 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	len;

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
